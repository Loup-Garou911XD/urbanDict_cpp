CC=g++
CXXFLAGS=-I/usr/lib/wx/include/gtk3-unicode-3.2 -I/usr/include/wx-3.2 -DWXUSINGDLL -D__WXGTK3__ -D__WXGTK__ -D_FILE_OFFSET_BITS=64 -pthread -pthread -lwx_gtk3u_xrc-3.2 -lwx_gtk3u_html-3.2 -lwx_gtk3u_qa-3.2 -lwx_gtk3u_core-3.2 -lwx_baseu_xml-3.2 -lwx_baseu_net-3.2 -lwx_baseu-3.2  -lcurl -ljsoncpp
DEPS = urban_dict_request.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CXXFLAGS)

urbanDict: urban_dict_request.o main.o
	$(CC) $(CXXFLAGS) -o main urban_dict_request.o main.o

clean:
	rm -f *.o main
