#!/bin/bash
# Simple bash script that pushes changes to github repository


# Prompt the user for a commit message
echo "Enter your commit message:"
read message

# Check if the message is not empty
if [ -z "$message" ]; then
    echo "Commit message cannot be empty. Aborting."
    exit 1
fi

# Add all changes to staging
git add .

# Commit with the provided message
git commit -m "$message"

# Push the changes to the remote repository
git push

# Confirm that the operations were successful
if [ $? -eq 0 ]; then
    echo "Changes have been successfully pushed."
else
    echo "An error occurred during the push operation."
fi