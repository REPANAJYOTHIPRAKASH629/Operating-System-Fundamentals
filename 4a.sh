echo "The list of File Names in the curent directory."
echo "Which have Read,Write and Execute permisions. "
for file in *
do
if [ -f $file ]
then
if [ -r $file -a -w $file -a -x $file ]
then
ls -l $file
fi
fi
done
