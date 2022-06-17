#include "photo_album.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Photo *create_photo(int id,const char *description){
	Photo *new_photo;

	new_photo = malloc(sizeof(Photo));
	if(new_photo == NULL){
		return NULL;
	}else{
		if(description != NULL){
			new_photo->description = malloc(strlen(description) + 1);
		}else{
			return NULL;
		}
	}
	new_photo->id = id;
	if(description == NULL){
		new_photo->description = NULL;
	}else {
		strcpy(new_photo->description,description);
	}
return new_photo;
}

void print_photo(Photo *photo){
	if(photo != NULL){
		if(photo->description != NULL){
			printf("Photo Id: %d, Description: %s\n", photo->id, photo->description);
		}else{
			printf("Photo Id: %d, Description: None\n", photo->id);
		}
	}	
}

void destroy_photo(Photo *photo){
	if(photo != NULL){
		free(photo->description);
		free(photo);
	}
}

void initialize_album(Album *album){

	if(album != NULL){
		album->size = 0;
	}
}

void print_album(const Album *album){
	int i;
	Photo *photo;

	if(album != NULL){

		if(album->size == 0){
			printf("Album has no photos.\n");
		}else{
			for(i = 0; i < album->size; i++){
				photo = album->all_photos[i];
				print_photo(photo);
			}
		}
	}
}
void destroy_album(Album *album){
	int i;

	if(album != NULL){
		for(i = 0; i < album->size; i++){
			destroy_photo(album->all_photos[i]);
		}
		album->size = 0;	
	}
}

void add_photo_to_album(Album *album,int id,const char *description){
	Photo *photo;
	int index;

	if(album != NULL && album->size < MAX_ALBUM_SIZE){
		index = album->size;
		photo = create_photo(id, description);
		album->all_photos[index] = photo;
		album->size++;
	}
}
