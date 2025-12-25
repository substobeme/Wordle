# Wordle

https://github.com/user-attachments/assets/b17ca922-aead-42c2-8755-bab030258853

This is a simple worlde c++ code which is containerized usin docker, done as a part of redhat preoboarding task for week 1 and week 2.

The game works as follows:
- You will have to make a guess within 6 chances of a 5 letter word
- If letter in your guess is exactly at the place of where it actually is in the word, it will be denoted by [G]
- If letter in your guess is not exactly at the place but is present in the wordm it will be denoted by(Y)
- Use these hints to guess the correct word

## How to run it in a system
Download the files(2 only) as it is, and run the following commands
- docker build -t wordle .
- docker run --rm -it wordle


