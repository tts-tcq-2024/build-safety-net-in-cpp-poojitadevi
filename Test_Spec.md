**Test Items**

The item under test is the generateSoundex function, which is responsible for converting a given name into its corresponding Soundex code.

**Test Scope**

**The tests cover:** <br>
Handling of empty strings <br>
Single character input <br>
Input with vowels and specific consonants that should be ignored <br>
Adjacent consonants mapping to the same Soundex digit <br>
Handling of longer names that require truncation <br>
Names with hyphens or spaces <br>
Names with non-alphabetic characters <br>

**Test Cases**

**Test Case 1**: Handling of Empty Strings <br>
Test ID: TC01 <br>
Objective: Ensure the function correctly handles an empty string. <br>
Input: "" (empty string) <br>
Expected Output: "" (empty Soundex code)

**Test Case 2:** Single Character Input <br>
Test ID: TC02 <br>
Objective: Ensure the function correctly generates the Soundex code for a single character. <br>
Input: Characters from 'A' to 'Z' <br>
Expected Output: <Character>000 (e.g., 'A' -> 'A000')

**Test Case 3:** Handling of Vowels and Specific Consonants <br>
Test ID: TC03 <br>
Objective: Ensure the function ignores vowels and specific consonants (H, W) when generating the Soundex code. <br>
Input: Various strings composed primarily of vowels and/or H, W <br>
Expected Output: Correct Soundex code (e.g., "AEIOU" -> "A000") 

**Test Case 4:** Adjacent Identical Consonants <br>
Test ID: TC04 <br>
Objective: Ensure that adjacent identical consonants are handled correctly, producing only one corresponding digit in the Soundex code. <br>
Input: Strings with two identical consonants (e.g., "BB", "CC") <br>
Expected Output: Correct Soundex code with a single digit for the consonant (e.g., "BB" -> "B100")

**Test Case 5:** Handling of Long Names <br>
Test ID: TC05 <br>
Objective: Ensure the function correctly truncates long names to produce a four-character Soundex code. <br>
Input: Various long names (e.g., "Albuquerque", "Washington") <br>
Expected Output: Correct four-character Soundex code (e.g., "Albuquerque" -> "A421")

**Test Case 6:** Names with Hyphens or Spaces <br>
Test ID: TC06 <br>
Objective: Ensure the function handles names with hyphens or spaces correctly, generating the proper Soundex code. <br>
Input: Names with hyphens and spaces (e.g., "Jean-Luc Picard", "Bruce Wayne") <br>
Expected Output: Correct Soundex code (e.g., "Jean-Luc Picard" -> "J452")

**Test Case 7:** Names with Non-Alphabetic Characters <br>
Test ID: TC07 <br>
Objective: Ensure the function correctly handles names that contain non-alphabetic characters, ignoring them when generating the Soundex code. <br>
Input: Names with non-alphabetic characters (e.g., "O'Brien", "O'Brien") <br>
Expected Output: Correct Soundex code ignoring non-alphabetic characters (e.g., "O'Brien" -> "O165") <br>

