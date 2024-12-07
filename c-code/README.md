

https://github.com/user-attachments/assets/1d7474f2-81ec-455a-8bf1-d6cbf1d7addb

# Cyber Range Dashboard: Creating and Testing `CyberRangeFormWithConsole`

## Overview
This guide walks you through creating, compiling, and testing a Windows application named `CyberRangeFormWithConsole` using Visual Studio Code on Windows, transferring the source file to Kali Linux, and compiling it using MinGW-w64. The resulting executable is designed for the Cyber Range Dashboard.

---

## Steps to Create, Compile, and Test

### Step 1: Download and Install Visual Studio Code on Windows 10
1. **Download Visual Studio Code**:
   - Open a web browser and go to [https://code.visualstudio.com/](https://code.visualstudio.com/).
   - Click **Download for Windows** and save the installer.

2. **Install Visual Studio Code**:
   - Run the downloaded installer.
   - Follow the on-screen instructions to complete the installation.
   - Ensure you check the options to add Visual Studio Code to the PATH during installation.

3. **Launch Visual Studio Code**:
   - Open Visual Studio Code from the Start Menu.

---

### Step 2: Write the C Code
1. **Create a new file** in Visual Studio Code:
   - Click `File > New File`.
   - Copy and paste the C code for `CyberRangeFormWithConsole` into the editor.

2. **Save the file**:
   - Click `File > Save As`.
   - Save the file as `CyberRangeFormWithConsole.c` to your USB drive.

---

### Step 3: Prepare the USB for Transfer
1. Verify that the file `CyberRangeFormWithConsole.c` is on the USB drive.
2. Safely eject the USB drive from your Windows 10 machine.

---

### Step 4: Open Kali Linux VM
1. Insert the USB drive into the host machine and mount it in your Kali Linux VM:
   - In your VM software (e.g., VirtualBox or VMware), attach the USB drive to the VM.
   - The USB drive should automatically mount in the Kali Linux filesystem. If not, manually mount it.

2. Open the terminal in Kali Linux and navigate to the USB drive:
   ```bash
   cd /media/<your-username>/<usb-drive-name>
   ```
   Replace `<your-username>` and `<usb-drive-name>` with the appropriate values. Use `lsblk` or `df -h` to locate the mounted USB drive if needed.

3. Confirm the presence of the `.c` file:
   ```bash
   ls
   ```
   You should see the file `CyberRangeFormWithConsole.c`.

---

### Step 5: Install MinGW-w64 on Kali Linux
1. Install MinGW-w64:
   ```bash
   sudo apt update
   sudo apt install mingw-w64
   ```

2. Verify the installation:
   ```bash
   x86_64-w64-mingw32-gcc --version
   ```

---

### Step 6: Compile the C Code
1. Compile the `CyberRangeFormWithConsole.c` file:
   ```bash
   x86_64-w64-mingw32-gcc CyberRangeFormWithConsole.c -o CyberRangeFormWithConsole.exe -mwindows
   ```
   - **CyberRangeFormWithConsole.c**: The source file.
   - **-o CyberRangeFormWithConsole.exe**: Specifies the output file name as `CyberRangeFormWithConsole.exe`.
   - **-mwindows**: Ensures the application is built as a Windows GUI application, suppressing the console.

2. Confirm the creation of the `.exe` file:
   ```bash
   ls
   ```
   The file `CyberRangeFormWithConsole.exe` should appear.

3. Transfer the compiled `.exe` back to the USB drive:
   ```bash
   cp CyberRangeFormWithConsole.exe /media/<your-username>/<usb-drive-name>
   ```

---

### Step 7: Test the Application on Windows
1. Safely eject the USB from your Kali Linux VM and insert it into a Windows machine.
2. Run the `CyberRangeFormWithConsole.exe` directly from the USB:
   - Double-click the file.
   - The application should launch, showing the form with buttons.

---

## Summary of Commands
### In Kali Linux:
1. Navigate to the USB:
   ```bash
   cd /media/<your-username>/<usb-drive-name>
   ```

2. Compile the C file:
   ```bash
   x86_64-w64-mingw32-gcc CyberRangeFormWithConsole.c -o CyberRangeFormWithConsole.exe -mwindows
   ```

3. Transfer the `.exe` back to the USB:
   ```bash
   cp CyberRangeFormWithConsole.exe /media/<your-username>/<usb-drive-name>
   ```

---

## Purpose
This application is a foundational piece for the **Cyber Range Dashboard**, providing hands-on experience in developing and testing Windows-based GUI applications while utilizing Kali Linux for compilation and testing workflows.

--- 

Let me know if you need additional details or adjustments!
