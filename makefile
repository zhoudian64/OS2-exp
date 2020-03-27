all: exp1 exp2 link_exp mmap_exp io_exp mount_exp
	echo "all compiled."

exp2: locker check_locker
	echo "locker check_locker compiled."
	
locker: locker.c
	cc locker.c -o locker

check_locker: lock_checker.c
	cc lock_checker.c -o lock_checker

exp1: sender receiver
	echo "sender receiver compiled."

sender: sender.c
	cc sender.c -o sender

receiver: receiver.c
	cc receiver.c -o receiver

link_exp: link_example.c unlink_example.c
	cc unlink_example.c -o unlink_example
	cc link_example.c -o link_example

mmap_exp: mmap_example.c
	cc mmap_example.c -o mmap_example

io_exp: io.c
	cc io.c -o io

mount_exp: mount_example.c
	cc mount_example.c -o mount_example

clean:
	rm io link_example lock_checker locker mmap_example mount_example
	rm receiver sender unlink_example
