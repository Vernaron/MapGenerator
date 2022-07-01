git ls-files | grep -v "\.o\|\.exe\|git\|README\|\.txt" | xargs wc -l 
read TEST