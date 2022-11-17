PROG=rfkill-input-handler-disable

$(PROG): $(PROG).c
	$(CC) -o $@ $<

clean:
	$(RM) $(PROG)

install: $(PROG)
	install -m 700 -o root -g root $(PROG) /usr/local/sbin
	install -m 644 -o root -g root $(PROG).service /etc/systemd/system
	@echo "Remember to:"
	@echo "    sudo systemctl daemon-reload"
	@echo "    sudo systemctl start $(PROG).service"
	@echo "    sudo systemctl enable $(PROG).service"

uninstall:
	$(RM) /usr/local/sbin/$(PROG)
	$(RM) /etc/systemd/system/$(PROG).service
