rfkill-input-handler-disable
============================

A simple service that tells the Linux kernel not to handle `KEY_RFKILL` input events, ie. not to toggle the rfkill status when that key (usually marked as "Airplane mode" or "No Wifi") gets pressed.

As long as nothing else in userspace (eg. graphical desktop environments) is toggling rfkill in reaction to `KEY_RFKILL` being pressed, then this service will prevent that key from toggling the rfkill state.

This is great if you rarely use the "Airplane mode" feature, but find it annoying to lose your Wifi connection if you accidentally press that key.  Plus, it frees up the key for rebinding to some other purpose.

Installation
------------

You need a working C compiler.  To compile the `rfkill-input-handler-disable` program, run:

    make

You can run the `rfkill-input-handler-disable` program as any user with access to `/dev/rfkill`.  When the program starts up, you should see `rfkill: input handler disabled` appear in `dmesg`.  The process then does nothing, but while it's present, the kernel won't handle `KEY_RFKILL`.  When the process ends, you'll see `rfkill: input handler enabled` in `dmesg`, and the kernel will resume handling `KEY_RFKILL`.

A systemd service definition file is also included.  To install it and the binary, run:

    sudo make install
	sudo systemctl daemon-reload
    sudo systemctl enable rfkill-input-handler-disable.service
    sudo systemctl start rfkill-input-handler-disable.service

