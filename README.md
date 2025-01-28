# nRFLEAudioUnicast
Repo for LE Audio Application for unicast application

# Git Command to add VS Code into remote repository 
git init
git add .
git commit -m " "

# Configure Git account
git config --global user.email "you@example.com" 
git config --global user.name "Your Name"

git remote add origin https://github.com/embdev61/nRFLEAudioUnicast.git
git remote -v
# Push to remote branch 
git push -u origin master

# PS C:\ncs\v2.9.0\nrf\applications\nrf5340_audio> git push -u origin main       
# error: src refspec main does not match any
# error: failed to push some refs to 'https://github.com/embdev61/nRFLEAudioUnicast.git'

# Issue w.r.t remote branch name . To resolve this checkout the main branch
git branch
git checkout -b main
git pull
git fetch origin
git merge origin/main
git status
git add .
git push origin main

# Add the changes into remote repo
git status
git add .
git commit -m " "
git push origin main

# Merge Branch
To merge the master branch into the main branch of your Git repository, follow these steps:

Ensure Both Branches Are Up-to-Date:

Fetch the latest changes from the remote repository:
git fetch origin

Switch to the main branch:
git checkout main

Pull the latest changes into the main branch:
git pull origin main

Switch to the master branch:
git checkout master

Pull the latest changes into the master branch:
git pull origin master

Merge master into main:

Switch back to the main branch:
git checkout main

Merge the master branch into main:
git merge master

If the branches have unrelated histories (e.g., if they were created independently), you might encounter an error during the merge. To address this, use the --allow-unrelated-histories flag:
git merge master --allow-unrelated-histories

This flag allows Git to merge branches that do not share a common base. 
STACK OVERFLOW
Resolve Any Merge Conflicts:

If there are conflicts during the merge, Git will notify you. Open the conflicting files, resolve the conflicts, and then stage the resolved files:
git add <file>

After resolving all conflicts, commit the merge:
git commit -m "Merge master into main"
Push the Merged main Branch to the Remote Repository:

Push the updated main branch to the remote repository:
git push origin main
By following these steps, you'll successfully merge the master branch into the main branch of your Git repository.

# Link
https://youtu.be/JB7YD7OKm5g

https://youtu.be/45uNJvo6djA

https://youtu.be/64F3G2fiMBc


