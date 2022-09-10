#!/bin/sh

script_base_name=$1

touch ${script_base_name}.cc
# touch ../build/shell_${script_base_name}.sh

cat <<EOF0 > ../build/shell_${script_base_name}.sh
#!/bin/sh

g++ -o ${script_base_name} ../src/${script_base_name}.cc
./${script_base_name} << EOF
< enter input >
EOF
EOF0

chmod +x ../build/shell_${script_base_name}.sh
