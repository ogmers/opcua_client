#pragma once

#ifndef __TREE_NODE_H__
#define __TREE_NODE_H__

#include <iostream>
#include <vector>
#include <iomanip>
#include <memory>
#include <fstream>

#include "tools.h"
#include "data_types.h"
#include <open62541/client_highlevel.h>
#include <open62541/plugin/log_stdout.h>


/* Class Tree_Node */
/* ^^^^^^^^^^^^^^^ */

class Tree_Node
{
public:

    Tree_Node(std::string);

    Tree_Node(node actual_node);

    ~Tree_Node();

    static node
    init_node(void);

    static void 
    init_node(node &init_node);

    /* Add node */
    void
    add_child(std::shared_ptr<Tree_Node> shared);

    static int
    get_response_data(UA_ReferenceDescription *ref, 
                    node &current_node);

    void
    set_node_job(std::shared_ptr<JOB> &job);

    void
    set_node_(node);

    /* Get values and states */
    int
    get_namespace(void);

    id_type
    get_ident_type(void);

    std::string 
    get_ident_string(void);

    int
    get_ident_numeric(void);

    /* Get strings console print */
    std::string
    get_display_name(void);

    std::string
    get_namespace_index(void);

    std::string
    get_identifier(void);

    std::string
    get_node_type(void);

    std::string
    get_identifier_type(void);

    /* Console and file prints */
    void
    print_node(void);

    void
    print_tree_console(void);

    void
    print_tree_console_(const std::string &prefix = "", 
                        bool is_last = true);

    void
    print_tree_file(const std::string &filename);

    void
    print_tree_file_(std::ofstream &file,
                        const std::string &prefix = "",
                        bool is_last = true);

private:

    const std::string printer_identifier_;

    node node_;
    std::vector<std::shared_ptr<Tree_Node>> children_;

};

#endif // __TREE_NODE_H__