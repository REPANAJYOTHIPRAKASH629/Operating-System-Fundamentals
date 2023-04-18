echo " Enter the word to be searched"
read word
echo "Enter the filename to be used"
read flname
echo "the no. of times the word ['$word'] occured in the file."
grep -o $word $flname|wc -l
echo " the no of line that contains ['$word'] is"
grep -c $word $flname
