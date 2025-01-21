

https://github.com/user-attachments/assets/ae41797b-b148-4531-8cb0-009f446bfc94





# ROT13 Decoder

A simple Windows Forms Application written in C# that performs **ROT13 encoding/decoding**. This project is designed to encode or decode text using the **ROT13 cipher**, which shifts each letter of the alphabet by 13 places.

---

## 🚀 Features

- **User-Friendly Interface**: 
  - Input text in the text box.
  - Click the "Rotate" button to encode/decode the input text.
  - View the output in a separate read-only text box.
  
- **ROT13 Algorithm**:
  - Handles both uppercase and lowercase letters.
  - Leaves non-alphabetic characters (e.g., spaces, punctuation) unchanged.

- **Extensible Design**:
  - Easy to expand with new features, like theme support, clearing input/output, or additional ciphers.

---

## 🛠️ How It Works

1. **Input**: Users type a string into the input text box (`txtInput`).
2. **Button Click**: When the "Rotate" button (`cmdRotate`) is clicked, the app processes the input text using the ROT13 cipher.
3. **Output**: The encoded or decoded text is displayed in the output text box (`txtOutput`).

---

## 📂 Project Structure

### Key Files:
- **`Form1.cs`**: Contains the main logic for the application, including the ROT13 algorithm and event handlers for the button click.
- **`Form1.Designer.cs`**: Auto-generated code for the Windows Form design (text boxes, button, layout, etc.).
- **`Program.cs`**: Entry point for the application.

---

## 🔍 Code Explanation

### The ROT13 Algorithm
The **ROT13 algorithm** is implemented as a helper method in `Form1.cs`. Here's the method:

```csharp
private string Rot13(string input)
{
    char[] buffer = input.ToCharArray();

    for (int i = 0; i < buffer.Length; i++)
    {
        char letter = buffer[i];

        // Check if it's an uppercase letter
        if (letter >= 'A' && letter <= 'Z')
        {
            letter = (char)(((letter - 'A' + 13) % 26) + 'A');
        }
        // Check if it's a lowercase letter
        else if (letter >= 'a' && letter <= 'z')
        {
            letter = (char)(((letter - 'a' + 13) % 26) + 'a');
        }

        buffer[i] = letter;
    }

    return new string(buffer);
}
```

## Input: A string (e.g., Vasbezngvba-Frphevgl-2025).
**Processing:** Each letter is shifted 13 places in the alphabet:

## Uppercase letters (A-Z) and lowercase letters (a-z) are handled separately.
- Non-alphabetic characters are skipped.
- Output: Encoded or decoded string (e.g.,Information-Security-2025)




