
all: ASet.o AndClauseLinkedList.o DNFCMD.o
	gcc ASet.o AndClauseLinkedList.o DNFCMD.o -o DNFConverter.o

AndClauseLinkedList.o: ADNF.h AndClauseLinkedList.c
	gcc -c AndClauseLinkedList.c

DNFCMD.o: ADNF.h DNFCMD.c
	gcc -c DNFCMD.c

ASet.o: ASet.c ASet.h
	gcc -c ASet.c
