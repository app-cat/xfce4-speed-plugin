/*
 * Copyright 2003,2005,2006 Bernhard Walle <bernhard@bwalle.de>
 * Copyright 2010 Florian Rivoal <frivoal@gmail.com>
 * -------------------------------------------------------------------------------------------------
 * 
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the Free
 *  Software Foundation; either version 2 of the License, or (at your option)
 *  any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 675 Mass
 * Ave, Cambridge, MA 02139, USA.
 *
 * ------------------------------------------------------------------------------------------------- 
 */
#ifndef NET_H
#define NET_H

#include "os.h"
#include "slurm.h"

#define MSGSIZE 1024
#define UP_UPDATE_INTERVAL 20
#define IP_UPDATE_INTERVAL 20
#define IP_ADDRESS_LENGTH 64
#define INTERFACE_NAME_LENGTH 33

#ifndef gettext_noop
#define gettext_noop(String) String
#endif

/** errorcodes */
typedef enum 
{
    UNKNOWN_ERROR,
    PROC_DEVICE_NOT_FOUND,
    INTERFACE_NOT_FOUND
} errorcode_t;


/**
 * We need this because we cannot use static variables. Using of static variables allows
 * us not to use several instances of the plugin.
 * I know that this change makes it a bit incompatible with wormulon, but that's the
 * price to pay ...
 */
typedef struct
{
    char            old_interface[INTERFACE_NAME_LENGTH];
    double          backup_in;
    errorcode_t     errorcode;
    double          backup_out;
    double          cur_in;
    double          cur_out;
    struct timeval  prev_time;
    int             correct_interface;          /* treated as boolean */
    IfData          ifdata;
    char            ip_address[IP_ADDRESS_LENGTH];
    int             ip_update_count;
    DataStats       stats;
    int             up;
    int             up_update_count;
    FILE*           proc_net_dev;
} netdata;


/**
 * Initializes the netload plugin. Used to set up inital values. This function must
 * be called after each change of the network interface.
 * @param   device      The network device, e.g. <code>ippp0</code> for ISDN on Linux.
 * @return  <code>true</code> if no error occurs, <code>false</code> otherwise. If there's
 *          an error, the error message may be set
 */
int init_speed(netdata* data, const char* device);

/**
 * Gets the current speed. You must call init_speed() once before you use this function!
 * @param in        Input load in byte/s.
 * @param out       Output load in byte/s.
 * @param tot       Total load in byte/s.
 */
void get_current_speed(netdata* data, unsigned long *in, unsigned long *out, unsigned long *tot);

/**
 * Returns the name of the network interface.
 * @param data      object
 * @return The name. String resides in data and you don't have to free the string.
 *         On error, returns NULL.
 */
char* get_name(netdata* data);

/**
 * Check to see if an interface is up.
 * @param data      object
 * @return  <code>true</code> if interface is up, <code>false</code> otherwise.
 */
int get_interface_up(netdata* data);


/**
 * Returns the IP address of the network interface
 * @param data     object
 * @return the IP address as string, NULL on error.
 */
char* get_ip_address(netdata* data);

/**
 * Should be called to do cleanup work.
 */
void close_netload(netdata* data);

#endif /* NET_H */
