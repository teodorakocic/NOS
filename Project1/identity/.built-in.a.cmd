cmd_identity/built-in.a := rm -f identity/built-in.a;  printf "identity/%s " identity.o | xargs ar cDPrST identity/built-in.a
