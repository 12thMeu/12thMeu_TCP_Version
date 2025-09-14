# PowerShell script to execute 'hemtt build --no-rap' and copy files

# Set the working directory
$scriptPath = Get-Location
$toolsPath = Join-Path $scriptPath "tools"
$pboIncludePath = Join-Path $scriptPath "pbo_include"
$hemttOutPath = Join-Path $scriptPath ".hemttout\build\addons"

# Execute 'hemtt build --no-rap'
Start-Process -FilePath "$toolsPath\hemtt" -ArgumentList "build", "--no-bin" -WorkingDirectory $scriptPath -Wait

# Copy files from './pbo_include' to './.hemttout/build/addons'
Copy-Item -Path "$pboIncludePath\*" -Destination $hemttOutPath -Recurse -Force

Write-Host "Files copied successfully!"