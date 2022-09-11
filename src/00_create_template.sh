#!/bin/sh
# Create templates for C++ and shell scripts.
#
# Usage:
# ./00_create_template basename
# -> src/basename.cc ../example/shell_basename.sh

script_base_name=$1

touch ${script_base_name}.cc

cat <<EOF0 > ../example/shell_${script_base_name}.sh
#!/bin/sh

g++ -o ${script_base_name} ../src/${script_base_name}.cc
./${script_base_name} << EOF
< enter input >
EOF
EOF0

chmod +x ../example/shell_${script_base_name}.sh
