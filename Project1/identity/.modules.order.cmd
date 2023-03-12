cmd_identity/modules.order := {  :; } | awk '!x[$$0]++' - > identity/modules.order
