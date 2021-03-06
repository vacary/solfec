/*
 * goc.h
 * Copyright (C) 2008, 2009 Tomasz Koziara (t.koziara AT gmail.com)
 * -------------------------------------------------------------------
 * geometric object contact detection
 */

/* This file is part of Solfec.
 * Solfec is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * Solfec is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with Solfec. If not, see <http://www.gnu.org/licenses/>. */

#include "shp.h"

#ifndef __goc__
#define __goc__

typedef enum
{CONTACT_DETECT,
 CONTACT_UPDATE} GOCDO;

/* detect or update contact data between two geometric objects
 * ----------------------------------------------------------------------------------
 *  CONTACT_DETECT => return 0 for no contact
 *                    return 1 if the first object holds the outward normal
 *                    return 2 if the seccond object holds the outward normal
 *                    ---------------------------------------------------------------
 *                    positive 'gap' is never reported in detection mode; only when
 *                    objects do overlap a contact is detected
 * ----------------------------------------------------------------------------------
 *  CONTACT_UPDATE => return 0 for no contact
 *                    return 1 for updated contact with no surface pair change
 *                    return 2 for updated contact when the surface pair has changed
 *                    ---------------------------------------------------------------
 *                    in an updated contact the 'gap' can be positive;
 *                    normal is assumed and kept outward to the first body
 * ----------------------------------------------------------------------------------
 *  the returned 'area' will always be equal 1.0 if one of the objects is curved;
 *  otherwise this is the actual flat area of contact between two object surfaces
 */
int gobjcontact (
    GOCDO action, short paircode, /* 'paircode' must be generated by GOBJ_Pair_Code () */
    SHAPE *oneshp, void *onegobj, /* the first shape and the geometric object inside of it */
    SHAPE *twoshp, void *twogobj, /* the seccond ... */
    double onepnt [3], /* spatial point of the first object */
    double twopnt [3], /* spatial point of the seccond object */
    double normal [3], /* normal => outward to the 'n' th object, where 'n' is returned */
    double *gap, /* gap between objects */
    double *area, /* area of contact */
    int spair [2], /* surface pair codes */
    TRI **ptri, int *ntri); /* contact surface */

/* get distance between two objects (output closest point pair in p, q) */
double gobjdistance (short paircode, SGP *one, SGP *two, double *p, double *q);

#endif
