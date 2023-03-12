cmd_/home/teodora/add_module/add_module.mod := printf '%s\n'   add_module.o | awk '!x[$$0]++ { print("/home/teodora/add_module/"$$0) }' > /home/teodora/add_module/add_module.mod
