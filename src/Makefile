CC = gcc
BIN_PATH=./bin
CFLAG = -g -Wall

ALL:$(BIN_PATH)/cat $(BIN_PATH)/cp $(BIN_PATH)/echo $(BIN_PATH)/mv $(BIN_PATH)/pwd

$(BIN_PATH)/cat:cat.c
	$(CC) -o $@ $< $(CFLAG)

$(BIN_PATH)/cp:cp.c
	$(CC) -o $@ $< $(CFLAG)

$(BIN_PATH)/echo:echo.c
	$(CC) -o $@ $< $(CFLAG)

$(BIN_PATH)/mv:mv.c
	$(CC) -o $@ $< $(CFLAG)

$(BIN_PATH)/pwd:pwd.c
	$(CC) -o $@ $< $(CFLAG)

clean:
	rm -rf ./bin/*