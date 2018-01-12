read file
new=$(echo "$file" | sed 's/.* > \(.*\) < .*/\1/'
echo $new
