#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "varintencode.h"
#include "varintdecode.h"

int LLVMFuzzerTestOneInput(char* data, size_t size) {
	int N = 5000;
	uint32_t * datain = malloc(N * sizeof(uint32_t));
	uint8_t * compressedbuffer = malloc(N * sizeof(uint32_t));
	uint32_t * recovdata = malloc(N * sizeof(uint32_t));
	for (int k = 0; k < N; ++k)
		datain[k] = 120;
	size_t compsize = vbyte_encode(datain, N, compressedbuffer); // encoding
	size_t compsize2 = masked_vbyte_decode(data, recovdata,
					N);
	assert(compsize == compsize2);
	free(datain);
	free(compressedbuffer);
	free(recovdata);
	return 0;
}

