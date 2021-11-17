#include "stencil.h"
#include <immintrin.h>
#include <strings.h>
void ApplyStencil(unsigned char *img_in, unsigned char *img_out, int width, int height) {
  
	__m256i val;
	char *aux[32];
	for (int i = 1; i < height-1; i++)
		for (int j = 1; j < width-1; j+=32) {
			//val = img_in[(i  )*width + j];
			__m256i ivalij=_mm256_loadu_si256((__m256i *)&img_in[(i)*width + j]);
			
			
			//img_in[(i-1)*width + j-1] 
			__m256i ivaliRjR=_mm256_loadu_si256((__m256i *)&img_in[(i-1)*width + j-1]);

			//img_in[(i-1)*width + j]
			__m256i ivaliRj=_mm256_loadu_si256((__m256i *)&img_in[(i-1)*width + j]);
			//img_in[(i-1)*width + j+1]
			__m256i ivaliRjP=_mm256_loadu_si256((__m256i *)&img_in[(i-1)*width + j+1]);
			//img_in[(i  )*width + j-1] 
			__m256i ivalijR=_mm256_loadu_si256((__m256i *)&img_in[(i  )*width + j-1] );
			//img_in[(i  )*width + j+1]
			__m256i ivalijP=_mm256_loadu_si256((__m256i *)&img_in[(i  )*width + j+1]); 
			//img_in[(i+1)*width + j-1] 
			__m256i ivaliPjR=_mm256_loadu_si256((__m256i *)&img_in[(i+1)*width + j-1] );			
			//img_in[(i+1)*width + j]
			__m256i ivaliPj=_mm256_loadu_si256((__m256i *)&img_in[(i+1)*width + j]); 
			//img_in[(i+1)*width + j+1];
			__m256i valiPjP=_mm256_loadu_si256((__m256i *)&img_in[(i+1)*width + j+1]);


			//val=ivalij;
			//val=_mm256_adds_epu8(_mm256_subs_epu8(ivalij,ivaliRjR),val);

			val=_mm256_subs_epu8(ivalij,ivaliRjR);
			
			val=_mm256_adds_epu8(_mm256_subs_epu8(ivalij,ivaliRj),val);
			
			val=_mm256_adds_epu8(_mm256_subs_epu8(ivalij,ivaliRjP),val);

			val=_mm256_adds_epu8(_mm256_subs_epu8(ivalij,ivalijR),val);

			val=_mm256_adds_epu8(_mm256_subs_epu8(ivalij,ivalijP),val);

			val=_mm256_adds_epu8(_mm256_subs_epu8(ivalij,ivaliPjR),val);

			val=_mm256_adds_epu8(_mm256_subs_epu8(ivalij,ivaliPj),val);

			val=_mm256_adds_epu8(_mm256_subs_epu8(ivalij,valiPjP),val);





//			val +=	-img_in[(i-1)*width + j-1] -   img_in[(i-1)*width + j] - img_in[(i-1)*width + j+1] 
//					-img_in[(i  )*width + j-1] + 7*img_in[(i  )*width + j] - img_in[(i  )*width + j+1] 
//					-img_in[(i+1)*width + j-1] -   img_in[(i+1)*width + j] - img_in[(i+1)*width + j+1];
//			if (val<0){
//				val=0;
//			}else val_out = (unsigned char)val;
//			if (val>255){
//				val_out=255;
//			}else val_out = (unsigned char)val;

			//img_out[i*width + j] = (unsigned char)(val_out);
			//_mm256_storeu_si256((float*)aux,siceof(aux));
			//strncat(&img_out[i*width + j],&val, sizeof(val));
			_mm256_storeu_si256(&img_out[i*width + j],val);
		}
}

void CopyImage(unsigned char *img_in, unsigned char *img_out, int width, int height) {

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			img_in[i*width + j] = img_out[i*width + j];
}
