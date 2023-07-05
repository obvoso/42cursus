read -p "Enter file to delete in git history like .env etc" files
git filter-branch --index-filter "git rm -rf --cached --ignore-unmatch $files" HEAD
echo "please command git push origin {remote branch}"
