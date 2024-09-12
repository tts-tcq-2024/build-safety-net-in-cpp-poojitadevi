Test Items
The item under test is the generateSoundex function, which is responsible for converting a given name into its corresponding Soundex code.

Test Scope


The tests cover:
Handling of empty strings
Single character input
Input with vowels and specific consonants that should be ignored
Adjacent consonants mapping to the same Soundex digit
Handling of longer names that require truncation
Names with hyphens or spaces
Names with non-alphabetic characters

Test Cases

Test Case 1: Handling of Empty Strings 
Test ID: TC01
Objective: Ensure the function correctly handles an empty string.
Input: "" (empty string)
Expected Output: "" (empty Soundex code)

Test Case 2: Single Character Input
Test ID: TC02
Objective: Ensure the function correctly generates the Soundex code for a single character.
Input: Characters from 'A' to 'Z'
Expected Output: <Character>000 (e.g., 'A' -> 'A000')

Test Case 3: Handling of Vowels and Specific Consonants
Test ID: TC03
Objective: Ensure the function ignores vowels and specific consonants (H, W) when generating the Soundex code.
Input: Various strings composed primarily of vowels and/or H, W
Expected Output: Correct Soundex code (e.g., "AEIOU" -> "A000")

Test Case 4: Adjacent Identical Consonants
Test ID: TC04
Objective: Ensure that adjacent identical consonants are handled correctly, producing only one corresponding digit in the Soundex code.
Input: Strings with two identical consonants (e.g., "BB", "CC")
Expected Output: Correct Soundex code with a single digit for the consonant (e.g., "BB" -> "B100")

Test Case 5: Handling of Long Names
Test ID: TC05
Objective: Ensure the function correctly truncates long names to produce a four-character Soundex code.
Input: Various long names (e.g., "Ashcraft", "Tymczak")
Expected Output: Correct four-character Soundex code (e.g., "Ashcraft" -> "A261")

Test Case 6: Names with Hyphens or Spaces
Test ID: TC06
Objective: Ensure the function handles names with hyphens or spaces correctly, generating the proper Soundex code.
Input: Names with hyphens and spaces (e.g., "Ruturaj-Gaikwad", "Virat Kohli")
Expected Output: Correct Soundex code (e.g., "Virat Kohli" -> "V632")

Test Case 7: Names with Non-Alphabetic Characters
Test ID: TC07
Objective: Ensure the function correctly handles names that contain non-alphabetic characters, ignoring them when generating the Soundex code.
Input: Names with non-alphabetic characters (e.g., "J'Bumrah", "Harish@15")
Expected Output: Correct Soundex code ignoring non-alphabetic characters (e.g., "J'Bumrah" -> "J156")

