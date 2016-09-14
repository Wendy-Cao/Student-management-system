FINAL:=main   #FINAL 代表main
OBJECT:=main.o administrator.o denglu.o teacher.o  student.c#这里的OBJECT 代表main.o fread_link.o
OPTIONS:=-g -Wall 
CC:=gcc
$(FINAL):$(OBJECT)
	$(CC) $^ -o $@ $(OPTIONS)  #$^表示分隔符分隔符分割之后的所有文件，$@表示目标文件，%.o表示所有文件的.o文件，%.c表示所有的.c文件
%.o:%.c
	$(CC) -c $< -o $@      #$< 表示分隔符分割的单个文件，clean： 删除操作 在终端上使用make clean 能执行下面的命令
clean:
	rm $(FINAL) $(OBJECT) 
