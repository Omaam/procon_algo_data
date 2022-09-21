#!/bin/sh
# Create templates for C++ and shell scripts.
#
# Example:
#   ./00_create_cscript basename c
#   ./00_create_ccscript basename cc

script_base_name=$1
langtype=$2

if [ ${langtype} = "c" ]; then
  touch ${script_base_name}.c
  cat <<EOF0 > ../example/shell_${script_base_name}.sh
#!/bin/sh

gcc -o ${script_base_name} ../src/${script_base_name}.c
./${script_base_name} << EOF
< enter input >
EOF
EOF0

elif [ ${langtype} = "cc" ]; then
  touch ${script_base_name}.cc
  cat <<EOF0 > ../example/shell_${script_base_name}.sh
#!/bin/sh

g++ -o ${script_base_name} ../src/${script_base_name}.cc
./${script_base_name} << EOF
< enter input >
EOF
EOF0
fi

chmod +x ../example/shell_${script_base_name}.sh
