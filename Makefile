INCLUDE_DIRS="asm-include"
SRC_DIRS="arduino-c" "avr" "c"
SRCS=

all: compile
                                                                               

compile:
	for dir in $$(ls | grep -v $(INCLUDE_DIRS)) ; do 	\
		if [ -d $$dir ] ; then 							\
			for src in $(SRC_DIRS); do					\
				src_dir="$$dir/$$src"				   ;\
				if [ ! -d $$src_dir ] ; then		    \
					echo "\e[1;31mDirectory $$src_dir"  \
					"does not exists\e[0m"			   ;\
					continue 						   ;\
				fi									   ;\
				make -sC $$src_dir				   	   ;\
				if [ "0" = $$? ] ; then				    \
					echo "\e[1;32m$$src_dir was built"  \
						 "\e[0m" 		   			   ;\
				else								    \
					echo "\e[1;31mFailed building"      \
						 "directory: $$src_dir"			\
						 "\e[0m"	   		   		   ;\
				fi									   ;\
			done									   ;\
		fi 											   ;\
	 done

clean:
	for dir in $$(ls | grep -v $(INCLUDE_DIRS)) ; do 	\
		if [ -d $$dir ] ; then 							\
			for src in $(SRC_DIRS); do					\
				src_dir="$$dir/$$src"				   ;\
				if [ ! -d $$src_dir ] ; then		    \
					continue						   ;\
				fi									   ;\
				make clean -sC $$src_dir	   		   ;\
				if [ "0" = $$? ] ; then			        \
					echo "\e[1;32m$$src_dir was cleaned"\
						 "\e[0m" 		   			   ;\
				else 								    \
					echo "\e[1;33m$$src_dir could not"  \
						 "be cleaned\e[0m" 		       ;\
				fi									   ;\
			done									   ;\
		fi 											   ;\
	 done


