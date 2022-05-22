#include <fmt/core.h>
#include <fmt/color.h>
#include <curl/curl.h>
#include <tidy.h>



size_t gotData(char *buffer,size_t itemSize,size_t numberOfItems,void *ignorThis = nullptr) {\
	fmt::print(fmt::fg(fmt::color::blue), "\nChunk Starting\n");
	size_t bytes = itemSize * numberOfItems;
	fmt::print("New Chunk Size {}\n", bytes);
	int lineNumber = 1;;
	fmt::print("{}\t",lineNumber);
	for (int i = 0; i < bytes; i++) {
		fmt::print("{}", buffer[i]);
		if (buffer[i] == '\n') {
			lineNumber++;
			fmt::print("{}\t", lineNumber);
		}
	}
	fmt::print(fmt::fg(fmt::color::red), "Chunk Ending\n");
	return bytes;
}


int main() {
	fmt::print("Hello world\n");
	fmt::print("{}\n",curl_version());

	CURL* curl = curl_easy_init();
	if (!curl) {
		fmt::print("Error Occured");
		return EXIT_FAILURE;
	}

	//Set Actions 
	CURLcode res;
	curl_easy_setopt(curl, CURLOPT_URL, "https://www.4chan.org/");
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, gotData);


	res = curl_easy_perform(curl);
	

	//Perform Our Actions

	curl_easy_cleanup(curl);
	return EXIT_SUCCESS;
}