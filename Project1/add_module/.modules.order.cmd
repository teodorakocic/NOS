cmd_/home/teodora/add_module/modules.order := {   echo /home/teodora/add_module/add_module.ko; :; } | awk '!x[$$0]++' - > /home/teodora/add_module/modules.order
