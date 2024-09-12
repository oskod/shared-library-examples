#include <stdio.h>
#include <dlfcn.h>

int main() {
	void *handle = dlopen("lib/libmylib.so", RTLD_LAZY);
	if (!handle) {
		printf("Library load failed: %s\n", dlerror());
		return -1;
	}

	int (*add)(int, int) = (int (*)(int, int)) dlsym(handle, "add");
	char *error = dlerror();
	if (!handle) {
		printf("Function load failed: %s\n", dlerror());
		return -1;
	}

	printf("a + b = %d\n", add(1, 5));

	dlclose(handle);

	return 0;
}