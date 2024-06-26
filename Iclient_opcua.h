#pragma once

#include <iostream>
#include <memory>

#include "Ijob_opcua.h"

namespace opcuac
{
    /**
     * Class ClientRIS - Reduced instruction set
     * ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    */
    class ClientRIS
    {
    public:
    
        virtual
        ~ClientRIS() = default;

        /**
         * Basics 
         * ^^^^^^
         * 
         * Each client must be initialized and connected. The user must decide how the 
         * connection is disconnected or how the processing of the tasks works.
        */

        /* Init client, init member values and start basic configuration. */
        virtual void
        init(void) = 0;

        /* Clean up and controlled shutdown of the client. */
        virtual void 
        disconnect(void) = 0;

        /* Client workbench. */
        virtual int
        run_iterate(void) = 0;

        /**
         * Printer services
         * ^^^^^^^^^^^^^^^^
         * 
         * These are not just methods that have been implemented exclusively for cab printers.
         * These services can be used to read and write the structure tree. 
        */

        /* Monitors the node and reports if the status or value changes. */
        virtual void
        add_monitored_item(jobsptr) = 0;

        /* Remove monitored item. */
        virtual void
        del_monitored_item(jobsptr) = 0;

        /* Read node attributes. */
        virtual void 
        read_node(jobsptr) = 0;

        /* Write node attributes. */
        virtual void
        write_node(jobsptr) = 0;

        /* Browse nodes structure. */
        virtual void
        browse(jobsptr) = 0;

        /**
         * Printer methods
         * ^^^^^^^^^^^^^^^
         * 
         * Only the pure virtual methods are currently implemented and usable. This interface 
         * gives you an overview of all methods that are available on the printer. feel free 
         * to implement additional methods. 
         * */

        /* Upload e.g. a label format or image file to a printer's storage device. */
        virtual void
        file_upload(jobsptr) = 0;

        /**
         * Prints given JScript or ZPL data directly on the printer. The method expects UTF-8 
         * content encoding. */
        virtual void
        print_data(jobsptr) = 0;

        /** 
         * Printer interpreter methods
         * ^^^^^^^^^^^^^^^^^^^^^^^^^^^
         * 
         * The methods in this area are only available if there is a label in the printer buffer. 
         */

        /* Make given number of copies from current label. */
        virtual void
        print_current_label(jobsptr) = 0;

    };

    /**
     * Class ClientCIS - Complex instruction set
     * ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    */
    class ClientCIS
    {
    public:

        virtual 
        ~ClientCIS() = default;

        /**
         * Basics 
         * ^^^^^^
         * 
         * Each client must be initialized and connected. The user must decide how the 
         * connection is disconnected or how the processing of the tasks works.
        */

        /* Attempts to connect the client several times. */
        virtual void
        connect(void) = 0;

        /**
         * Printer methods
         * ^^^^^^^^^^^^^^^
         * 
         * Only the pure virtual methods are currently implemented and usable. This interface 
         * gives you an overview of all methods that are available on the printer. feel free 
         * to implement additional methods. 
         * */

        /* Returns the last printed label in PNG format as processed by the printengine. */
        virtual void
        bitmap(jobsptr) = 0;

        /* Cancels the current print job. */
        virtual void
        cancel_job(jobsptr) = 0;

        /* Exports the printer's configuration in XML format. */
        virtual void
        export_settings(jobsptr) = 0;

        /* Delete given file on a printer's storage device. */
        virtual void
        file_delete(jobsptr) = 0;

        /* Download e.g. a label format or image file from a printer's storage device. */
        virtual void
        file_download(jobsptr) = 0;

        /* List files on given storage device. */
        virtual void
        file_list(jobsptr) = 0;

        /* Query for available fonts. */
        virtual void
        font_list(jobsptr) = 0;

        /**
         * Imports a custom TLS certificate in PEM format. This will override the supplied 
         * self-signed certificate. */
        virtual void
        import_certificateTLS(jobsptr) = 0;

        /* Imports an XML printer configuration. */
        virtual void
        import_settings(jobsptr) = 0;

        /* Returns the last printed label in PNG format with viewport adopted to job settings. */
        virtual void
        label_bitmap(jobsptr) = 0;

        /* Loads a label from any attached printer storage device. */
        virtual void
        load_label(jobsptr) = 0;

        /* Query for object availability. */
        virtual void
        query_object(jobsptr) = 0;

        /* Resets passwords to factory defaults. */
        virtual void
        reset_passwords(jobsptr) = 0;

        /* Resets to factory defaults. */
        virtual void
        reset_settings(jobsptr) = 0;

        /* Returns a screenshot of the printer's display in PNG format. */
        virtual void
        screen(jobsptr) = 0;

        /* Set or unset an I/O input, mostly adequate with PAUSE and LBLROT. */
        virtual void
        set_input(jobsptr) = 0;

        /* Sets an OPC UA servers URL for data retrieval in standalone mode. */
        virtual void
        set_opcua_client_url(jobsptr) = 0;

        /* Cancels all print jobs scheduled or currently printed by the printer. */
        virtual void
        total_cancel(jobsptr) = 0;

        /**
         * Triggers an I/O input, one of FSTLBL, REPRINT, START, LBLREM, JOBDEL, RSTERR, 
         * STOP or LBLFEED. PAUSE and LBLROT is not implemented as trigger, use SetInput 
         * instead. */
        virtual void
        trigger_input(jobsptr) = 0;

    };

    /**
     * Class IClient - Implemented OPC UA client interface 
     * ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
     */
    class IClient : public ClientRIS
    {
    public:

        virtual
        ~IClient() = default;

        virtual void
        init(void) override = 0;

        virtual void 
        disconnect(void) override = 0;

        virtual int
        run_iterate(void) override = 0;

        virtual void
        add_monitored_item(jobsptr) override = 0;

        virtual void
        del_monitored_item(jobsptr) override = 0;

        virtual void 
        read_node(jobsptr) override = 0;

        virtual void
        write_node(jobsptr) override = 0;

        virtual void
        browse(jobsptr) override = 0;

        virtual void
        file_upload(jobsptr) override = 0;

        virtual void
        print_data(jobsptr) override = 0;

        virtual void
        print_current_label(jobsptr) override = 0;

    };
    
} // namespace opcuac

/* Eof */