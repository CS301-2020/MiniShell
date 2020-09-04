hellomake: shell.c
	@echo "building shell..."
	gcc -o shell shell.c -w
	clear
	@echo "Starting shell..."
	./shell
	
