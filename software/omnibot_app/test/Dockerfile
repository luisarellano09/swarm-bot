# See https://aka.ms/customizecontainer to learn how to customize your debug container and how Visual Studio uses this Dockerfile to build your images for faster debugging.

# Stage 1: Base runtime image
FROM mcr.microsoft.com/dotnet/aspnet:9.0 AS base
WORKDIR /app

# Stage 2: Build environment
FROM mcr.microsoft.com/dotnet/sdk:9.0 AS build
ARG BUILD_CONFIGURATION=Release
WORKDIR /src

# Copy solution and project files for faster caching
COPY ../omnibot_app.sln ./
COPY ../test/test.csproj ./test/

# If there are other projects with dependencies, include them too
# COPY ../SomeLib/SomeLib.csproj ./SomeLib/

# Restore using the solution (faster rebuild if deps didn't change)
RUN dotnet restore omnibot_app.sln

# Copy the rest of the source code
COPY .. .

# Build only the target project
WORKDIR /src/test
RUN dotnet build test.csproj -c $BUILD_CONFIGURATION -o /app/build

# Stage 3: Publish
FROM build AS publish
ARG BUILD_CONFIGURATION=Release
RUN dotnet publish test.csproj -c $BUILD_CONFIGURATION -o /app/publish /p:UseAppHost=false

# Stage 4: Final runtime image
FROM base AS final
WORKDIR /app
COPY --from=publish /app/publish .
ENTRYPOINT ["dotnet", "test.dll"]
