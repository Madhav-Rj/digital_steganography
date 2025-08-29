/*
    Name: Madhava Raj B
    Id: 24018_225
    sec: I
    Date: 11/10/2024
    Project Discription: "Digital steganography" is the practice of concealing information within digital files, such as images
                 audio, or video, to prevent detection. It uses techniques to embed secret data in a way that is
                 imperceptible to the human eye or ear. This method enhances privacy and security by hiding
                 messages in plain sight. Common applications include secure communications and digital watermarking
*/

#include <stdio.h>
#include "encode.h"
#include "types.h"
#include <string.h>
#include "common.h"	

int main(int argc, char *argv[])
{
    EncodeInfo encInfo;
    uint img_size;
   if(argc < 4)
   {
    printf("Error : Insufficient arguments\n");
    printf("Usage:-\nFor encoding -> ./a.out -e <.bmp file> <secret file> [output file]\nFor Decoding -> ./a.out -d <.bmp file> [output file]\n");
    return e_failure;
   }
   else //comes to else part only if args >=4
   {
     if( check_operation_type(argv) == e_encode) // e_encode==e_encode ~=true for encode oparation //check_operation_type(argv) fun call.
     {
        printf("\n## ENCODING OPERATION IS SELECTED ##\n\n");
        EncodeInfo encInfo;//re
        if(read_and_validate_encode_args(argv, &encInfo) == e_success)//argv base of structure(EncodeInfo) variable -->encode.c line 10;
        {
            printf("INFO: Read and Validation for Encoding is Success\n");
            if(do_encoding(&encInfo) == e_success)
            {
				printf("\n--------------------------------------------");
                printf("\n##  ENCODING SUCCESSFULLY COMPLETED  ##\n");
				printf("---------------------------------------------\n");
            }
        }
      }
      else if(check_operation_type(argv)==e_decode)
	    {
		    printf("\n## DECODING OPERATION IS SELECTED ##\n");

		   if(argc >=2)
		    {
			   if(read_and_validate_decode_args(argv,&encInfo)==e_success)
			    {
				    printf("INFO: Validation Success\n");
				    if(do_decoding(&encInfo)==e_success)
				     {
						printf("\n----------------------------------------\n");
					    printf("##  DECODEING SUCCESSFULLY COMPLETED  ##\n");
						printf("-----------------------------------------\n");
				      }
			    }
				else
				{
					printf("\n## DECODING FAILED ##\n");
				}
		}
			else
			{
				printf("ERROR:Validation Error\nPlease Provide Required Files Through Command Line\n");
				printf("\n## DECODING FAILED ##\n");
				return e_failure;
			}
	}
	else
	{
		printf("ERROR:Pass Valid Operation Type\nEncoding: ./a.out -e <.bmp file> <.txt file> [Output file]\nDecoding: ./a.out -d <.bmp file> [output file]\n");
	}
    } 
    return 0;
}