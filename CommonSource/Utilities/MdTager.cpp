#include "MdTager.h"

CMdTager::CMdTager( void )
	: bufferLen(1024)
	, buffer(NULL)
{
	buffer    = new char [ bufferLen ];
	tempBases = new char [ bufferLen ];
	memset(buffer, 0, bufferLen);
	memset(tempBases, 0, bufferLen);

	zeroChar = '0';
}

void CMdTager::ExtendBuffer( const unsigned int& length ) {
	if ( buffer ) delete [] buffer;

	buffer = new char [ length + 10 ];
	memset(buffer, 0, bufferLen);
}

inline void CMdTager::InitializeVar( const char* reference, const char* query, const unsigned int& referenceLen ) {
	pMd  = buffer;
	pReference = (char*) reference;
	pQuery     = (char*) query;

	numBases       = referenceLen;
	currentPos     = 0;
	numBufferBytes = 0;
}

char* CMdTager::GetMdTag( const char* reference, const char* query, const unsigned int& referenceLen ) {
	
	// check the buffer size
	if ( ( referenceLen * 2 ) > bufferLen )
		ExtendBuffer( referenceLen * 2 );

	InitializeVar( reference, query, referenceLen );

	//char* tempBases = new char [CIGAR_BUFFER_SIZE];
	//const char zeroChar = '0';
	bool isPreviousInt = false;

	while(currentPos < numBases) {

		unsigned short testPos = currentPos;
		unsigned short operationLength = 0;
		int numWritten = 0;

		if ( ( pReference[currentPos] == pQuery[currentPos] ) || ( pReference[currentPos] == '-' ) ) {
			
			while ( ( pReference[testPos] != 0 ) && ( ( pReference[testPos] == pQuery[testPos] ) || ( pReference[testPos] == '-' ) ) ) {
				++testPos;
				++operationLength;
			}

			numWritten = sprintf_s(pMd, bufferLen, "%u", operationLength);

			isPreviousInt = true;

		} else if ( pQuery[currentPos] == '-' ) {
			
			char* ptr = tempBases;
			while ( pQuery[testPos] == '-' ) {
				memcpy( ptr, &pReference[testPos], 1 );
				ptr++;
				++testPos;
				++operationLength;
			}

			*ptr = 0;

			numWritten = sprintf_s(pMd, bufferLen, "^%s", tempBases);

			isPreviousInt = false;
		
		} else if ( pReference[currentPos] != pQuery[currentPos] ) {
			
			char* ptr = tempBases;
			unsigned short nTemp = 0;
			while ( ( pReference[testPos] != pQuery[testPos] ) && ( pReference[testPos] != '-' ) && ( pQuery[testPos] != '-' ) ) {
				
				if ( isPreviousInt ) {
					memcpy( ptr, &pReference[testPos], 1 );
					ptr++;
					nTemp += 1;
				}
				else {
					memcpy( ptr, &zeroChar, 1 );
					ptr++;
					memcpy( ptr, &pReference[testPos], 1 );
					ptr++;
					nTemp += 2;
				}
				isPreviousInt = false;

				++testPos;
				++operationLength;
			}

			*ptr = 0;

			numWritten = sprintf_s(pMd, bufferLen, "%s", tempBases);

			isPreviousInt = false;

		} else {
			printf("ERROR: CIGAR string generation failed.\n");
			exit(1);
		}

		// increment our position
		pMd            += numWritten;
		numBufferBytes += numWritten;
		currentPos     += operationLength;

	}

	*pMd = 0;

	return buffer;
}
