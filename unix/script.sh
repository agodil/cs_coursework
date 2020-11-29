# Homework 12

function usage
{
  echo "usage: $0 filename …"
  echo "ERROR: $1"
}

if [ $# -gt 0 ]
then
  name="Aamir Godil"
  echo $name
  date
  for arg
  do
    echo 
    if [ -e $arg ]
    then
      if ! grep -vq "^[0123456789][0123456789][0123456789]-[0123456789][0123456789]-[0123456789][0123456789][0123456789][0123456789], .*, .*$" $arg
      then
        starting_data=$arg
        awk '/-/ { print $0 }' $starting_data > noheader
        sed 's/-//' noheader | sed 's/-//' > nohyphens
        cut -f3 -d, nohyphens > first_name
        cut -f2 -d, nohyphens > last_name
        cut -f1 -d, nohyphens > id
        paste first_name last_name -d\  | sed 's/^ //' | sed 's/  / /' | sed 's/$/:/' > name
        paste name id -d\  > final
        echo $starting_data
        cat final
        rm noheader nohyphens first_name last_name id name final
      else usage "Invalid data in $arg"
      fi
    else usage "Could not find file $arg"
    fi
  done
else usage "Please enter a filename"
fi
