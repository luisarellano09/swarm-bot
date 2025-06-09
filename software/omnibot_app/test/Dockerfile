# Stage 1: Base runtime image
FROM mcr.microsoft.com/dotnet/aspnet:9.0 AS base
ARG BUILD_CONFIGURATION=Release
WORKDIR /app

# Stage 2: Build environment
FROM mcr.microsoft.com/dotnet/sdk:9.0 AS build
ARG BUILD_CONFIGURATION=Release
WORKDIR /src

# Copy solution and project files for cache efficiency
COPY ../omnibot_app.sln ./
COPY ../test/test.csproj ./test/

# Restore only
RUN dotnet restore omnibot_app.sln

# Copy the entire source tree
COPY .. .

# Build the project
WORKDIR /src/test
RUN dotnet build test.csproj -c $BUILD_CONFIGURATION -o /app/build --no-restore

# Stage 3: Publish (includes condition for debug symbols)
FROM build AS publish
ARG BUILD_CONFIGURATION=Release
RUN dotnet publish test.csproj -c $BUILD_CONFIGURATION -o /app/publish \
    /p:UseAppHost=false \
    /p:DebugType=full \
    /p:DebugSymbols=true \
    --no-restore

# Stage 4: Final runtime image
FROM base AS final
ARG BUILD_CONFIGURATION=Release
WORKDIR /app

# Set environment variables useful for containerized .NET apps
ENV DOTNET_RUNNING_IN_CONTAINER=true
ENV DOTNET_USE_POLLING_FILE_WATCHER=true

# Copy the published app
COPY --from=publish /app/publish .

# Entry point
ENTRYPOINT ["dotnet", "test.dll"]
