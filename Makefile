include Config.mk

all: Kirby

Kirby: Kirby.o

watch:
	while ! inotifywait -e modify *.cc; do make; done

clean:
	$(RM) *.o Kirby

.PHONY: all watch clean
