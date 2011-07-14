// Copyright 2011 Juri Glass, Mathias Runge, Nadim El Sayed 
// DAI-Labor, TU-Berlin
// 
// This file is part of libSML.
// 
// libSML is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// libSML is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with libSML.  If not, see <http://www.gnu.org/licenses/>.


#include <sml/sml_time.h>
#include <sml/sml_shared.h>
#include <sml/sml_number.h>
#include <stdio.h>

sml_time *sml_time_parse(sml_buffer *buf) {
	sml_time *tme = (sml_time *) malloc(sizeof(sml_time));
	
	if (sml_buf_get_next_type(buf) != SML_TYPE_LIST) {
		buf->error = 1;
		goto error;
	}
	
	if (sml_buf_get_next_length(buf) != 2) {
		buf->error = 1;
		goto error;
	}
	
	tme->tag = sml_u8_parse(buf);
	if (sml_buf_has_errors(buf)) goto error;
	
	tme->data = sml_u32_parse(buf);
	if (sml_buf_has_errors(buf)) goto error;
	
	return tme;
	
error:
	sml_time_free(tme);
	return 0;
}

void sml_time_write(sml_time *time, sml_buffer *buf) {
	if (time == 0) {
		sml_buf_optional_write(buf);
		return;
	}
	printf("NYI: %s (writing optional flag instead)\n", __FUNCTION__);
	sml_buf_optional_write(buf);
}

void sml_time_free(sml_time *tme) {
    if (tme) {
		sml_number_free(tme->tag);
		sml_number_free(tme->data);
        free(tme);
    }
}
