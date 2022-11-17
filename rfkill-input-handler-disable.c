#include <linux/rfkill.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	// According to the Linux open(2) man page, 3 is a special Linux thing which
	// means "check for read/write permissions, but don't actually allow
	// read/write on the fd - it's only good for ioctls".
	//
	// Similarly O_NONBLOCK is also useful as there's no intention to actually
	// read/write, we just want an fd so we can give it to ioctl.
	int fd = open("/dev/rfkill", 3 | O_NONBLOCK);
	if (fd < 0) {
		perror("/dev/rfkill");
		return 1;
	}

	ioctl(fd, RFKILL_IOCTL_NOINPUT);

	// Sleep forever.
	while (1) {
		pause();
	}

	return 0;
}
