# HELP - Simple Line Editor

## How to Run

Compile the program using:

```bash
gcc line_editor.c -o line_editor.exe
```

Run the program using:

```bash
.\line_editor.exe
```

## Commands

### 1. Insert Line

Adds a new line at the specified line number.

**Example:**

```text
Enter choice: 1
Enter line number: 2
Enter text: Hello World
```

### 2. Delete Line

Deletes a line from the document using its line number.

**Example:**

```text
Enter choice: 2
Enter line number: 2
```

### 3. Display Document

Displays all the lines currently stored in the document.

**Example:**

```text
Enter choice: 3

----- DOCUMENT -----
1. Hi World
2. This is my line editor.
```

### 4. Search

Searches for a word or text in the document.

**Example:**

```text
Enter choice: 4
Enter word to search: World
```

### 5. Find and Replace

Finds a word or text and replaces it with another text.

**Example:**

```text
Enter choice: 5
Enter word to find: Hello
Enter replacement: Hi
```

### 6. Line/Word Count

Displays the total number of lines and words in the document.

**Example:**

```text
Enter choice: 6

Number of lines: 2
Number of words: 7
```

### 7. Save File

Saves the current document to a text file.

**Example:**

```text
Enter choice: 7
Enter filename: document.txt
```

### 8. Load File

Loads a previously saved text file.

**Example:**

```text
Enter choice: 8
Enter filename: document.txt
```

### 9. Exit

Closes the line editor program.

**Example:**

```text
Enter choice: 9
```

## Notes

* Enter a valid line number when inserting or deleting.
* Save the document before exiting if you want to keep your changes.
* The program uses a menu-driven command-line interface.
