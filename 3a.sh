for file in "$@"
do
  if [ -e "$file" ]
  then
    upper=$(echo "$file" | tr '[:lower:]' '[:upper:]')
    mv "$file" "$upper"
    echo "Renamed $file to $upper"
  else
    echo "$file not found in current directory"
  fi
done
