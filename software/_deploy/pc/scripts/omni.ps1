# Define menu options
$menuOptions = @(
    @{ Label = "Update System"; Value = "Update" }
    @{ Label = "SSH into Raspberry Pi"; Value = "ssh_pi" }
    @{ Label = "SSH into Jetson NX"; Value = "ssh_nx" }
)

# Show menu using Out-GridView
$choice = $menuOptions | ForEach-Object {
    New-Object PSObject -Property $_
} | Out-GridView -Title "SBR Menu" -PassThru

if ($choice) {
    switch ($choice.Value) {
        "Update" {
            Write-Host "Running system update (Simulated)..."
            # Simulate updates - replace with real commands if using WSL or Cygwin
            # For real updates on Windows, you might consider:
            # Install-PackageProvider -Name NuGet -Force
            # Install-Module PSWindowsUpdate
            # Get-WindowsUpdate -Install
        }
        "ssh_pi" {
            ssh pi@omnipi
        }
        "ssh_nx" {
            ssh nx@omninx
        }
    }
} else {
    Write-Host "Menu canceled."
}
