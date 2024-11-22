Note to self: There currently is one thread for the TCP socket, one listener thread per data node, two compute threads and one IO thread. 

It would be nice to get this down to two threads globally (one for TCP socket and one listener for all data nodes in the domain), two compute threads and one IO thread.

My concern is we may end up racing to prevent scaling issues. The listener threads effectively go single threaded. Meaning latency with size. I would need to nest to create larger panels. In theory I support this. The issue is we risk sync lock up with deep hierarchy. My personal project will likely never care.