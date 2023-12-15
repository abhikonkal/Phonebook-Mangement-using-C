#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<assert.h>
typedef enum {PERSONAL_CONTACT,PROFESSIONAL_CONTACT}contact_type;
typedef struct tree_node_pro 
{
  	int height;
    char name[50];
    long long int phone_key;
    char email[50];
    int contact_type;
  	struct tree_node_pro *left_child_node, *right_child_node, *parent;
} Personal_Node;

typedef struct avl_tree_s 
{
  	int height, node_count_no;
  	struct tree_node_pro *root;
} Personal_AVL;
typedef struct tree_node_per 
{
  	int height;
    char name[50];
    long long int phone_key;
    char email[50];
    char office_number[50];
    char office[50];
    int contact_type;
  	struct tree_node_per *left_child_node, *right_child_node, *parent;
} Professional_Node;
typedef struct avl_tree_s2 
{
  	int height, node_count_no;
  	struct tree_node_per *root;
} Professional_AVL;
typedef struct phonebook
{
    Personal_AVL* tree_person;
    Professional_AVL* tree_prof;
}phonebook_trees;
//All-Pesronal_Functions----------------
void right_rotation_personal(Personal_AVL *tree, Personal_Node *node)
{
    assert(tree != NULL);
    assert(node != NULL);
    Personal_Node *l_child = node->left_child_node;
    if(node->parent == NULL)                                   //Rotating
    { 
        tree->root = l_child;
        l_child->parent = NULL;
    }
    else
    {
        if(node->phone_key < node->parent->phone_key)
        {
            node->parent->left_child_node = l_child;
        }
        else
        {
            node->parent->right_child_node = l_child;
        }
        l_child->parent = node->parent;
    }
    node->left_child_node = l_child->right_child_node;                 //Rearragenemnt process of all child nodes
    if(l_child->right_child_node)
    {
        l_child->right_child_node->parent = node;
    }
    l_child->right_child_node = node;
    node->parent = l_child;
    if(node)                                  //Upadating heights
    {
        node->height = get_height_personal(node);
    }
    if(l_child)
    {
        if(l_child->left_child_node)
        {
            l_child->left_child_node->height = get_height_personal(l_child->left_child_node);
        }
        l_child->height = get_height_personal(l_child);
    }
}
void left_rotation_personal(Personal_AVL *tree, Personal_Node *node)
{
    //Similar to right rotation
    assert(tree != NULL);
    assert(node != NULL);
    Personal_Node *r_child = node->right_child_node;
    if(node->parent == NULL)
    {
        tree->root = r_child;
        r_child->parent = NULL;
    }
    else
    {
        if(node->phone_key < node->parent->phone_key)
        {
            node->parent->left_child_node = r_child;
        }
        else
        {
            node->parent->right_child_node = r_child;
        }
        r_child->parent = node->parent;
    }
    node->right_child_node = r_child->left_child_node;
    if(r_child->left_child_node) 
    {
        r_child->left_child_node->parent = node;
    }
    r_child->left_child_node = node;
    node->parent = r_child;

    // Update the heights.
    if(node)
    {
        node->height = get_height_personal(node);
    }
    if(r_child)
    {
        if(r_child->right_child_node)
        {
            r_child->right_child_node->height = get_height_personal(r_child->right_child_node);
        }
        r_child->height = get_height_personal(r_child);
    }
}
void right_rotation_personal_on_name(Personal_AVL *tree, Personal_Node *node)
{
    //simlar to previous rotation but while giving parent new childs check names
    assert(tree != NULL);
    assert(node != NULL);
    Personal_Node *l_child = node->left_child_node;
    if(node->parent == NULL)                                            //Rotation on root
    {
        tree->root = l_child;
        l_child->parent = NULL;
    }
    else                                          //here on name
    {
        if(strcmp(node->name,node->parent->name)<0 || (strcmp(node->name,node->parent->name)==0 && node->phone_key<node->parent->phone_key))
        {
            node->parent->left_child_node = l_child;
        }
        else if(strcmp(node->name,node->parent->name)>0 || (strcmp(node->name,node->parent->name)==0 && node->phone_key>node->parent->phone_key))
        {
            node->parent->right_child_node = l_child;
        }
        l_child->parent = node->parent;
    }
    node->left_child_node = l_child->right_child_node;               // Rearranging the children nodes.
    if(l_child->right_child_node)
    {
        l_child->right_child_node->parent = node;
    }
    l_child->right_child_node = node;
    node->parent = l_child;
    if(node)                                                             //updating heights
    {
        node->height = get_height_personal(node);
    }
    if(l_child)
    {
        if(l_child->left_child_node)
        {
            l_child->left_child_node->height = get_height_personal(l_child->left_child_node);
        }
        l_child->height = get_height_personal(l_child);
    }
}
void left_rotation_personal_on_name(Personal_AVL *tree, Personal_Node *node)
{
    assert(tree != NULL);
    assert(node != NULL);
    Personal_Node *r_child = node->right_child_node;
    if(node->parent == NULL)
    {
        tree->root = r_child;
        r_child->parent = NULL;
    }
    else
    {
        if(strcmp(node->name,node->parent->name)<0 || (strcmp(node->name,node->parent->name)==0 && node->phone_key<node->parent->phone_key))
        {
            node->parent->left_child_node = r_child;
        }
        else if(strcmp(node->name,node->parent->name)>0 || (strcmp(node->name,node->parent->name)==0 && node->phone_key>node->parent->phone_key))
        {
            node->parent->right_child_node = r_child;
        }
        r_child->parent = node->parent;
    }
    node->right_child_node = r_child->left_child_node;
    if(r_child->left_child_node) 
    {
        r_child->left_child_node->parent = node;
    }
    r_child->left_child_node = node;
    node->parent = r_child;
    if(node)
    {
        node->height = get_height_personal(node);
    }
    if(r_child)
    {
        if(r_child->right_child_node)
        {
            r_child->right_child_node->height = get_height_personal(r_child->right_child_node);
        }
        r_child->height = get_height_personal(r_child);
    }
}
Personal_AVL * personal_tree_maker(Personal_Node *node)
{
    assert(node != NULL);
    Personal_AVL *tree = (Personal_AVL *)malloc(sizeof(Personal_AVL));
    if(tree == NULL)
    {
        printf("Malloc Failure,Exiting while creating a new tree from a node.\n");
        exit(1);
    }
    tree->root = node; 
    tree->height = 0;
    tree->node_count_no = 1;
    return tree;
}
Personal_AVL *make_personal_tree_empty()
{
    Personal_AVL *new_tree = (Personal_AVL *)malloc(sizeof(Personal_AVL));
    if(new_tree == NULL)
    {
        printf("Malloc Failure,Exiting while creating an empty tree.\n");
        exit(1);
    }
    new_tree->root = NULL;
    new_tree->height = -1;
    new_tree->node_count_no = 0;
    return new_tree;
}
Personal_Node * personal_node_maker()
{
    Personal_Node *new_node = (Personal_Node *)malloc(sizeof(Personal_Node));
    if(new_node == NULL)
    {
        printf("Malloc Failure,Exiting while generating a new node.\n");
        exit(1); 
    }
    printf("Enter the name of the contact: \n");
    fgets(new_node->name,50,stdin);
    printf("Enter the phone number of the contact: \n");
    scanf("%lld",&(new_node->phone_key));
    fflush(stdin);
    printf("Enter the email of contact: \n");
    fgets(new_node->email,50,stdin);
    new_node->contact_type=PERSONAL_CONTACT;
    new_node->left_child_node = new_node->right_child_node = new_node->parent = NULL;
    new_node->height = 0;
    return new_node;
}
void personal_check_in(Personal_AVL *tree, Personal_Node *node)
{
    assert(tree != NULL);
    assert(node != NULL);
    int bal = balance_personal(node); 
    if(node->parent == NULL) //root case
    {
        return;
    }
    Personal_Node *parent = node->parent;
    int p_bal = balance_personal(parent);
    //balacing the tree
    if(node->phone_key < parent->phone_key)
    {
        if(p_bal == 0)
        {
            // Exit
            return;
        }
        else if(p_bal == -1)
        {
        personal_check_in(tree, parent);
        }
        else if(p_bal < -1)
        {
            if(bal == -1)
            {
	            right_rotation_personal(tree, parent);
            }
            else if(bal == 1)
            {
	            left_rotation_personal(tree, parent->left_child_node);
	            right_rotation_personal(tree, parent);
            }
            else
            {
	            printf("Error Occured,Exiting(error place check_in_personal).\n"); //this wont occur normally
	            exit(2);
            }
        }
        else
        {
            printf("Error Occured,Exiting(error place check_in_personal).\n");
            exit(2);
        }
    }
    else
    {
        if(p_bal <= 0)
        {
            return;
        }
        else if(p_bal == 1)
        { 
            personal_check_in(tree, parent);
        }
        else if(p_bal > 1)
        {
            if(bal == 1)
            { 
	            left_rotation_personal(tree, parent);
            }
            else if(bal == -1)
            {
	            right_rotation_personal(tree, parent->right_child_node);
	            left_rotation_personal(tree, parent);
            }
            else
            {
	            printf("Error Ocuured,Exiting(error place check_in_personal).\n");
	            exit(2);
            }
        }   
        else
        {
            printf("Error Ocuured,Exiting(error place check_in_personal).\n");
            exit(2);
        }
    }
}
void personal_check_out(Personal_AVL *tree, Personal_Node *node)
{
    assert(tree != NULL);
    assert(node != NULL);
    Personal_Node *parent = node->parent;
    int bal = balance_personal(node);
    //balancing and rotating
    if(bal < -1)
    {
        int l_bal = balance_personal(node->left_child_node);
        if(l_bal == -1)
        {
            right_rotation_personal(tree, node);
        }
        else if(l_bal == 1)
        {
            left_rotation_personal(tree, node->left_child_node);
            right_rotation_personal(tree, node);
        }
        else
        {
            right_rotation_personal(tree, node);
        }
    }
    else if(bal > 1)
    {
        int r_bal = balance_personal(node->right_child_node);
        if(r_bal == 1)
        {
            left_rotation_personal(tree, node);
        }
        else if(r_bal == -1)
        {
            right_rotation_personal(tree, node->right_child_node);
            left_rotation_personal(tree, node);
        }
        else
        {
            left_rotation_personal(tree, node);
        }
    }
    if(parent) 
    {
        personal_check_out(tree, parent);
    }
}
//inline function substitues the code where the function is called
inline int get_int_max_personal(int a, int b)
{
    return (a > b) ? a : b;
}
int get_height_personal(Personal_Node *node)
{
    assert(node != NULL);
    int l_height = -1;
    int r_height = -1;
    if(node->left_child_node)
    {
        l_height = node->left_child_node->height;
    }
    if(node->right_child_node) 
    {
        r_height = node->right_child_node->height;
    }
    return get_int_max_personal(l_height, r_height) + 1;
}

int balance_personal(Personal_Node *node)
{
    assert(node != NULL);
    int l_height = -1;
    int r_height = -1;
    if(node->left_child_node) 
    {
        l_height = node->left_child_node->height;
    }
    if(node->right_child_node) 
    {
        r_height = node->right_child_node->height;
    }
    node->height = get_int_max_personal(l_height, r_height) + 1;
    return r_height - l_height;
}
//display
void print_node_personal(Personal_Node* node)
{
    if(node!=NULL)
    {
        fputs(node->name,stdout);
        printf("%lld\n",node->phone_key);
        fputs(node->email,stdout);
        fputs("\n",stdout);
        fputs("---------------------------------------\n",stdout);
        fputs("                                        \n",stdout);
    }
}
void inorder_personal(Personal_Node* root)  
{
    if(root==NULL)                                 
    {
        return;
    }
    inorder_personal(root->left_child_node);
    print_node_personal(root);
    inorder_personal(root->right_child_node);
}
void inorder_traversal_personal(Personal_AVL* tree)
{
    fputs("This prints phonebook in ascending order\n",stdout);
    inorder_personal(tree->root);
}
void inorder_personal_reverse(Personal_Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder_personal_reverse(root->right_child_node);
    print_node_personal(root);
    inorder_personal_reverse(root->left_child_node);
}
void inorder_traversal_personal_reverse(Personal_AVL* tree)
{
    fputs("This prints phonebook in descending order\n",stdout);
    inorder_personal_reverse(tree->root); 
}
//insert,delete,search
int insert_new_personal_data(Personal_AVL *tree)
{
    assert(tree != NULL); // Check arguments.
    Personal_Node *new_node = personal_node_maker();
    if(tree->root == NULL)
    {
        // emoty Tree.
        tree->root = new_node;
        new_node->parent = NULL;
        tree->height = 0;
        tree->node_count_no++;
        return 1;
    }
    else
    {
        Personal_Node *active = tree->root;
        while(1)
        {
            if(new_node->phone_key < active->phone_key)
            {
	            // New node inserted left of active.
	            if(active->left_child_node == NULL)
                {
	                // Insertion
	                active->left_child_node = new_node;
	                new_node->parent = active;
	                tree->node_count_no++;
	                personal_check_in(tree, new_node);
	                tree->height = tree->root->height;
	                return 1;
	            }

	        active = active->left_child_node;
            }
            else if(new_node->phone_key > active->phone_key) //right here
            {
	            if(active->right_child_node == NULL)
                {
	                active->right_child_node = new_node;
                    new_node->parent = active;
                    tree->node_count_no++;
                    personal_check_in(tree, new_node);
                    tree->height = tree->root->height;
                    return 1;
                }
                active = active->right_child_node; 
            }
            else
            {
                return 0; //duplicate case 
            }
        }
    }
    printf("Insertion Failed.\n");
    exit(2);
}
int delete_new_personal_data(int key, Personal_AVL *tree)
{
    assert(tree != NULL);
    Personal_Node *del_node = NULL;
    if(!search_personal_data(key, tree, &del_node))
    {
        return 0;
    }

    if(del_node)
    {
        Personal_Node *repl = del_node->left_child_node;
        if(repl == NULL)
        {
            repl = del_node->right_child_node;
        }
        else
        {
            while(repl->right_child_node)
            {
	            repl = repl->right_child_node;
            }
        }

        Personal_Node *rebalance = NULL;
        if(repl)
        {
            if(repl->parent != del_node) 
            {
                rebalance = repl->parent;
            }
            if(repl != del_node->right_child_node)
            {
	            repl->right_child_node = del_node->right_child_node;
	            if(del_node->right_child_node) 
                {
                    del_node->right_child_node->parent = repl;
                }
            }
            if(repl->parent != del_node)
            {
                repl->parent->right_child_node = repl->left_child_node;
                if(repl->left_child_node) 
                {
                    repl->left_child_node->parent = repl->parent;
                }
                repl->left_child_node = del_node->left_child_node;
                del_node->left_child_node->parent = repl;
            }
        }
        else
        {
            if(!rebalance && del_node->parent) 
            {
                rebalance = del_node->parent;
            }
        }
        if(del_node->parent)
        {
            if(del_node->phone_key < del_node->parent->phone_key)
            {
	            del_node->parent->left_child_node = repl;
            }
            else
            {
                del_node->parent->right_child_node = repl;
            }
            if(repl){repl->parent = del_node->parent;}
        }
        else
        {
            tree->root = repl;
            if(repl) {repl->parent = NULL;}
        }
        if(rebalance)
        {
            personal_check_out(tree, rebalance);
        }
        else
        {
            if(repl){personal_check_out(tree, repl);}
        }
        if(tree->root)
        {
            tree->height = tree->root->height;
        }
        else
        {
            tree->height = -1;
        }
        tree->node_count_no--;
        free(del_node);
        del_node = NULL;
        return 1;
    }
}   
int search_personal_data(int key, Personal_AVL *tree, Personal_Node **node)
{
    assert(tree != NULL);
    assert(node != NULL);
    if(tree->root == NULL)
    {
        *node = NULL;
        return 0;
    }
    *node = tree->root;
    while(1)
    {
        if(key < (*node)->phone_key)
        {
            if((*node)->left_child_node == NULL)
            {
	            return 0;
            }
            *node = (*node)->left_child_node;
        }
        else if(key > (*node)->phone_key)
        {
            if((*node)->right_child_node == NULL)
            {
	            return 0;
            }
            *node = (*node)->right_child_node;
        }
        else
        {
            return 1;
        }
    }
}
int edit_data_personal(int key, Personal_AVL * tree)
{
    assert(tree!=NULL);
    Personal_Node* edit;
    if(!search_personal_data(key,tree,&edit))
    {
        printf("Node not found\n");
        return 0;
    }
    else
    {
        printf("Fields avaliable for editing \n1.name\n2.email\n");
        printf("Enter field(complete field for eg type name to edit name) u wish to edit enter all to edit all(excluding phonenum)\n");
        char field[50];
        scanf("%s",field);
        if(strcmp(field,"all")==0)
        {
            printf("Enter new name\n");
            char name[50];
            fgets(name,50,stdin);
            printf("Enter new email\n");
            char email[50];
            fgets(email,50,stdin);
            strcpy(edit->name,name);
            strcpy(edit->email,email);
            return 1;
        }
        else if(strcmp(field,"name")==0)
        {
            printf("Enter new name\n");
            char name[50];
            fgets(name,50,stdin);
            strcpy(edit->name,name);
            return 1;
        }
        else if(strcmp(field,"email")==0)
        {
            printf("Enter new email\n");
            char email[50];
            scanf("%s",email);
            strcpy(edit->email,email);
            return 1;
        }
        else
        {
            printf("Invalid field\n");
            return 0;
        }
    }
}
void print_range_personal(Personal_Node* root,int min_range,int max_range)
{
    if(min_range>max_range) //ensures keys are in right order
    {
        int temp=min_range;
        min_range=max_range;
        max_range=temp;
    }
    if(root==NULL)
    {
        return;
    }
    if(min_range<root->phone_key)
    {
        print_range_personal(root->left_child_node,min_range,max_range);
    }
    if(min_range<=root->phone_key && max_range>=root->phone_key)
    {
        print_node_personal(root);
    }
    print_range_personal(root->right_child_node,min_range,max_range);
}
Personal_Node* copy_node(Personal_Node* node)//create copy of data
{
    Personal_Node *new_node = (Personal_Node *)malloc(sizeof(Personal_Node));
    if(new_node == NULL)
    {
        printf("Malloc Failure,Exiting while generating a new node.\n");
        exit(1); 
    }
    strcpy(new_node->name,node->name);
    strcpy(new_node->email,node->email);
    new_node->phone_key=node->phone_key;
    new_node->contact_type=PERSONAL_CONTACT;
    new_node->left_child_node = new_node->right_child_node = new_node->parent = NULL;
    new_node->height = 0;
    return new_node;
}
void check_in_personal_name(Personal_AVL *tree, Personal_Node *node)
{
    assert(tree != NULL);
    assert(node != NULL);
    int bal = balance_personal(node); 
    if(node->parent == NULL)
    {
        return;
    }
    Personal_Node *parent = node->parent;
    int p_bal = balance_personal(parent);
    if(strcmp(node->name,parent->name)<0 || (strcmp(node->name,parent->name)==0 && node->phone_key<parent->phone_key))
    {
        if(p_bal == 0)
        {
            return;
        }
        else if(p_bal == -1)
        {
            check_in_personal_name(tree, parent);
        }
        else if(p_bal < -1)
        {
            if(bal == -1)
            {
	            right_rotation_personal_on_name(tree, parent);
            }
            else if(bal == 1)
            {
	            left_rotation_personal_on_name(tree, parent->left_child_node);
	            right_rotation_personal_on_name(tree, parent);
            }
            else
            {
	            printf("Error Ocuured,Exiting(error place check_in_personal).\n");
	            exit(2);
            }
        }
        else
        {
            printf("Error Ocuured,Exiting(error place check_in_personal).\n");
            exit(2);
        }
    }
    else if(strcmp(node->name,parent->name)>0 || (strcmp(node->name,parent->name)==0 && node->phone_key>parent->phone_key))
    {
        if(p_bal <= 0)
        {
            return;
        }
        else if(p_bal == 1)
        {
            check_in_personal_name(tree, parent);
        }
        else if(p_bal > 1)
        {
            if(bal == 1)
            {
	            left_rotation_personal_on_name(tree, parent);
            }
            else if(bal == -1)
            {
	            right_rotation_personal_on_name(tree, parent->right_child_node);
	            left_rotation_personal_on_name(tree, parent);
            }
            else
            {
	            printf("Error Ocuured,Exiting(error place check_in_personal).\n");
	            exit(2);
            }
        }   
        else
        {
            printf("Error Ocuured,Exiting(error place check_in_personal).\n");           //we wont get these errors 
            exit(2);
        }
    }
}
int insert_personal_by_name(Personal_AVL* tree,Personal_Node* node)
{
    assert(tree != NULL); 
    Personal_Node *new_node = copy_node(node);
    if(tree->root == NULL)
    {
        tree->root = new_node;
        new_node->parent = NULL;
        tree->height = 0;
        tree->node_count_no++;
        return 1;
    }
    else
    {
        Personal_Node *active = tree->root;
        while(1)
        {
            if(strcmp(new_node->name,active->name)<0 || (strcmp(new_node->name,active->name)==0 && new_node->phone_key<active->phone_key))
            {
	            if(active->left_child_node == NULL)
                {
	                active->left_child_node = new_node;
	                new_node->parent = active;
	                tree->node_count_no++;
	                check_in_personal_name(tree, new_node);
	                tree->height = tree->root->height;
	                return 1;
	            }
	        active = active->left_child_node;
            }
            else if(strcmp(new_node->name,active->name)>0 || (strcmp(new_node->name,active->name)==0 && new_node->phone_key>active->phone_key))
            {
	            if(active->right_child_node == NULL)
                {
	                active->right_child_node = new_node;
                    new_node->parent = active;
                    tree->node_count_no++;
                    check_in_personal_name(tree, new_node);
                    tree->height = tree->root->height;
                    return 1;
                }
                active = active->right_child_node; 
            }
            else
            {
                return 0;
            }
        }
    }
    printf("Insertion Failed.\n");
    exit(2);   
}
void create_name_tree_personal(Personal_AVL* tree,Personal_Node* root)
{
    if(root==NULL)
    {
        return;
    }
    insert_personal_by_name(tree,root);
    create_name_tree_personal(tree,root->left_child_node);
    create_name_tree_personal(tree,root->right_child_node);
}
void cleaner_personal(Personal_Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cleaner_personal(root->left_child_node);
    cleaner_personal(root->right_child_node);
    free(root);
}
void clean_personal(Personal_AVL* tree)
{
    cleaner_personal(tree->root);
    free(tree);
}
//professional functions similar to personal just having Professiona_AVL in place of personal---------------------------------------
void right_rotation_professional_name(Professional_AVL *tree, Professional_Node *node)
{
    assert(tree != NULL);
    assert(node != NULL);
    Professional_Node *l_child = node->left_child_node;
    if(node->parent == NULL)
    {
        tree->root = l_child;
        l_child->parent = NULL;
    }
    else
    {
        if(strcmp(node->name,node->parent->name)<0 || (strcmp(node->name,node->parent->name)==0 && node->phone_key<node->parent->phone_key))
        {
            node->parent->left_child_node = l_child;
        }
        else if(strcmp(node->name,node->parent->name)>0 || (strcmp(node->name,node->parent->name)==0 && node->phone_key>node->parent->phone_key))
        {
            node->parent->right_child_node = l_child;
        }
        l_child->parent = node->parent;
    }
    node->left_child_node = l_child->right_child_node;
    if(l_child->right_child_node)
    {
        l_child->right_child_node->parent = node;
    }
    l_child->right_child_node = node;
    node->parent = l_child;
    if(node)
    {
        node->height = get_height_Professional(node);
    }
    if(l_child)
    {
        if(l_child->left_child_node)
        {
            l_child->left_child_node->height = get_height_Professional(l_child->left_child_node);
        }
        l_child->height = get_height_Professional(l_child);
    }
}
void left_rotation_professional_name(Professional_AVL *tree, Professional_Node *node)
{
    assert(tree != NULL);
    assert(node != NULL);
    Professional_Node *r_child = node->right_child_node;
    if(node->parent == NULL)
    {
        tree->root = r_child;
        r_child->parent = NULL;
    }
    else
    {
        if(strcmp(node->name,node->parent->name)<0 || (strcmp(node->name,node->parent->name)==0 && node->phone_key<node->parent->phone_key))
        {
            node->parent->left_child_node = r_child;
        }
        else if(strcmp(node->name,node->parent->name)>0 || (strcmp(node->name,node->parent->name)==0 && node->phone_key>node->parent->phone_key))
        {
            node->parent->right_child_node = r_child;
        }
        r_child->parent = node->parent;
    }
    node->right_child_node = r_child->left_child_node;
    if(r_child->left_child_node) 
    {
        r_child->left_child_node->parent = node;
    }
    r_child->left_child_node = node;
    node->parent = r_child;
    if(node)
    {
        node->height = get_height_Professional(node);
    }
    if(r_child)
    {
        if(r_child->right_child_node)
        {
            r_child->right_child_node->height = get_height_Professional(r_child->right_child_node);
        }
        r_child->height = get_height_Professional(r_child);
    }
}
//rotations
void rotate_right_Professional(Professional_AVL *tree, Professional_Node *node)
{
    assert(tree != NULL);
    assert(node != NULL);
    Professional_Node *l_child = node->left_child_node;
    if(node->parent == NULL)
    {
        tree->root = l_child;
        l_child->parent = NULL;
    }
    else
    {
        if(node->phone_key < node->parent->phone_key)
        {
            node->parent->left_child_node = l_child;
        }
        else
        {
            node->parent->right_child_node = l_child;
        }
        l_child->parent = node->parent;
    }
    node->left_child_node = l_child->right_child_node;
    if(l_child->right_child_node)
    {
        l_child->right_child_node->parent = node;
    }
    l_child->right_child_node = node;
    node->parent = l_child;
    if(node)
    {
        node->height = get_height_Professional(node);
    }
    if(l_child)
    {
        if(l_child->left_child_node)
        {
            l_child->left_child_node->height = get_height_Professional(l_child->left_child_node);
        }
        l_child->height = get_height_Professional(l_child);
    }
}
void rotate_left_Professional(Professional_AVL *tree, Professional_Node *node)
{
    assert(tree != NULL);
    assert(node != NULL);
    Professional_Node *r_child = node->right_child_node;
    if(node->parent == NULL)
    {
        tree->root = r_child;
        r_child->parent = NULL;
    }
    else
    {
        if(node->phone_key < node->parent->phone_key)
        {
            node->parent->left_child_node = r_child;
        }
        else
        {
            node->parent->right_child_node = r_child;
        }
        r_child->parent = node->parent;
    }
    node->right_child_node = r_child->left_child_node;
    if(r_child->left_child_node) 
    {
        r_child->left_child_node->parent = node;
    }
    r_child->left_child_node = node;
    node->parent = r_child;
    if(node)
    {
        node->height = get_height_Professional(node);
    }
    if(r_child)
    {
        if(r_child->right_child_node)
        {
            r_child->right_child_node->height = get_height_Professional(r_child->right_child_node);
        }
        r_child->height = get_height_Professional(r_child);
    }
}
void check_in_professional_name(Professional_AVL *tree, Professional_Node *node)
{
    assert(tree != NULL);
    assert(node != NULL);
    int bal = balance_Professional(node);
    if(node->parent == NULL) 
    {
        return;
    }
    Professional_Node *parent = node->parent;
    int p_bal = balance_Professional(parent);
    if(strcmp(node->name,parent->name)<0 || (strcmp(node->name,parent->name)==0 && node->phone_key<parent->phone_key))
    {
        if(p_bal == 0)
        {
            return;
        }
        else if(p_bal == -1)
        {
            check_in_professional_name(tree, parent);
        }
        else if(p_bal < -1)
        {
            if(bal == -1)
            {
	            right_rotation_professional_name(tree, parent);
            }
            else if(bal == 1)
            {
	            left_rotation_professional_name(tree, parent->left_child_node);
	            right_rotation_professional_name(tree, parent);
            }
            else
            {
	            printf("Error Ocuured,Exiting(error place check_in_proof).\n");
	            exit(2);
            }
        }
        else
        {
            printf("Error Ocuured,Exiting(error place check_in_prof).\n");
            exit(2);
        }
    }
    else if(strcmp(node->name,parent->name)>0 || (strcmp(node->name,parent->name)==0 && node->phone_key>parent->phone_key))
    {
        if(p_bal <= 0)
        {
            return;
        }
        else if(p_bal == 1)
        {
            check_in_professional_name(tree, parent);
        }
        else if(p_bal > 1)
        {
            if(bal == 1)
            {
	            left_rotation_professional_name(tree, parent);
            }
            else if(bal == -1)
            {
	            right_rotation_professional_name(tree, parent->right_child_node);
	            left_rotation_professional_name(tree, parent);
            }
            else
            {
	            printf("Error Ocuured,Exiting(error place check_in_personal).\n");
	            exit(2);
            }
        }   
        else
        {
            printf("Error Ocuured,Exiting(error place check_in_personal).\n");
            exit(2);
        }
    }
}
Professional_AVL * make_Professional_tree_from_node(Professional_Node *node)
{
    assert(node != NULL);
  

    Professional_AVL *tree = (Professional_AVL *)malloc(sizeof(Professional_AVL));
    if(tree == NULL)
    {
        printf("Malloc Failure,Exiting while creating a new tree from a node.\n");
        exit(1);
    }

    tree->root = node; 
    tree->height = 0;
    tree->node_count_no = 1;
    return tree;
}
Professional_AVL *make_Professional_tree_empty()
{
    Professional_AVL *new_tree = (Professional_AVL *)malloc(sizeof(Professional_AVL));
    if(new_tree == NULL)
    {
        printf("Malloc Failure,Exiting while creating an empty tree.\n");
        exit(1);
    }
    new_tree->root = NULL;
    new_tree->height = -1;
    new_tree->node_count_no = 0;
    return new_tree;
}
Professional_Node * make_Professional_node()
{
    Professional_Node *new_node = (Professional_Node *)malloc(sizeof(Professional_Node));
    if(new_node == NULL)
    {
        printf("Malloc Failure,Exiting while generating a new node.\n");
        exit(1); 
    }
    printf("Enter the name of the contact: \n");
    fgets(new_node->name,50,stdin);
    printf("Enter the phone number of the contact: \n");
    scanf("%lld",&(new_node->phone_key));
    fflush(stdin);
    printf("Enter the email of contact: \n");
    fgets(new_node->email,50,stdin);
    printf("Enter the office number of contact: \n");
    fgets(new_node->office_number,50,stdin);
    printf("Enter the name of office of contact: \n");
    fgets(new_node->office,50,stdin);
    new_node->contact_type=PROFESSIONAL_CONTACT;
    new_node->left_child_node = new_node->right_child_node = new_node->parent = NULL;
    new_node->height = 0;
    return new_node;
}
//avl checks
void Professional_check_in(Professional_AVL *tree, Professional_Node *node)
{
    assert(tree != NULL);
    assert(node != NULL);

    int bal = balance_Professional(node); 

    if(node->parent == NULL) 
    {
        return;
    }
    Professional_Node *parent = node->parent;
    int p_bal = balance_Professional(parent);
    if(node->phone_key < parent->phone_key)
    {
        if(p_bal == 0)
        {
            return;
        }
        else if(p_bal == -1)
        {
        Professional_check_in(tree, parent);
        }
        else if(p_bal < -1)
        {
            if(bal == -1)
            {
	            rotate_right_Professional(tree, parent);
            }
            else if(bal == 1)
            {
	            rotate_left_Professional(tree, parent->left_child_node);
	            rotate_right_Professional(tree, parent);
            }
            else
            {
	            printf("Error Ocuured,Exiting(error place check_in_personal).\n");
	            exit(2);
            }
        }
        else
        {
            printf("Error Ocuured,Exiting(error place check_in_personal).\n");
            exit(2);
        }
    }
    else
    {
        if(p_bal <= 0)
        {
            return;
        }
        else if(p_bal == 1)
        {
            Professional_check_in(tree, parent);
        }
        else if(p_bal > 1)
        {
            if(bal == 1)
            {
	            rotate_left_Professional(tree, parent);
            }
            else if(bal == -1)
            {
	            rotate_right_Professional(tree, parent->right_child_node);
	            rotate_left_Professional(tree, parent);
            }
            else
            {
	            printf("Error Ocuured,Exiting(error place check_in_personal).\n");
	            exit(2);
            }
        }   
        else
        {
            printf("Error Ocuured,Exiting(error place check_in_personal).\n");
            exit(2);
        }
    }
}
void Professional_check_out(Professional_AVL *tree, Professional_Node *node)
{
    assert(tree != NULL);
    assert(node != NULL);
    Professional_Node *parent = node->parent;
    int bal = balance_Professional(node);

    if(bal < -1)
    {
        int l_bal = balance_Professional(node->left_child_node);
        if(l_bal == -1)
        {
            rotate_right_Professional(tree, node);
        }
        else if(l_bal == 1)
        {
            rotate_left_Professional(tree, node->left_child_node);
            rotate_right_Professional(tree, node);
        }
        else
        {
            rotate_right_Professional(tree, node);
        }
    }
    else if(bal > 1)
    {

        int r_bal = balance_Professional(node->right_child_node);

        if(r_bal == 1)
        {
            rotate_left_Professional(tree, node);
        }
        else if(r_bal == -1)
        {
            rotate_right_Professional(tree, node->right_child_node);
            rotate_left_Professional(tree, node);
        }
        else
        {
            rotate_left_Professional(tree, node);
        }
    }

    if(parent) 
    {
        Professional_check_out(tree, parent);
    }
}
inline int get_int_max_Professional(int a, int b)
{
    return (a > b) ? a : b;
}
int get_height_Professional(Professional_Node *node)
{
    assert(node != NULL);

    int l_height = -1;
    int r_height = -1;
    if(node->left_child_node)
    {
        l_height = node->left_child_node->height;
    }
    if(node->right_child_node) 
    {
        r_height = node->right_child_node->height;
    }
  
    return get_int_max_Professional(l_height, r_height) + 1;
}
int balance_Professional(Professional_Node *node)
{
    assert(node != NULL);

    int l_height = -1;
    int r_height = -1;
    if(node->left_child_node) 
    {
        l_height = node->left_child_node->height;
    }
    if(node->right_child_node) 
    {
        r_height = node->right_child_node->height;
    }

    node->height = get_int_max_Professional(l_height, r_height) + 1;
    return r_height - l_height;
}
void print_node_Professional(Professional_Node* node)
{
    if(node!=NULL)
    {
        fputs(node->name,stdout);
        printf("%lld\n",node->phone_key);
        fputs(node->email,stdout);
        fputs(node->office,stdout);
        fputs(node->office_number,stdout);
        fputs("\n",stdout);
        fputs("__________________________________________\n",stdout);
        fputs("\n",stdout);
    }
}
void inorder_Professional(Professional_Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder_Professional(root->left_child_node);
    print_node_Professional(root);
    inorder_Professional(root->right_child_node);
}
void inorder_traversal_Professional(Professional_AVL* tree)
{
    fputs("This prints phonebook in ascending order\n",stdout);
    inorder_Professional(tree->root);
}
void inorder_professional_reverse(Professional_Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder_professional_reverse(root->right_child_node);
    print_node_Professional(root);
    inorder_professional_reverse(root->left_child_node);
}
void inorder_traversal_professional_reverse(Professional_AVL* tree)
{
    fputs("This prints phonebook in descending order\n",stdout);
    inorder_professional_reverse(tree->root);   
}
//insert,delete,search
int key_insert_newProfessional(Professional_AVL *tree)
{
    assert(tree != NULL);

    Professional_Node *new_node = make_Professional_node();
  
    if(tree->root == NULL)
    {
        tree->root = new_node;
        new_node->parent = NULL;
        tree->height = 0;
        tree->node_count_no++;
        return 1;
    }
    else
    {
        Professional_Node *active = tree->root;
    
        while(1)
        {
            if(new_node->phone_key < active->phone_key)
            {
	            if(active->left_child_node == NULL)
                {
	                active->left_child_node = new_node;
	                new_node->parent = active;
	                tree->node_count_no++;
	                Professional_check_in(tree, new_node);
	                tree->height = tree->root->height;
	                return 1;
	            }

	        active = active->left_child_node;
            }
            else if(new_node->phone_key > active->phone_key)
            {
	            if(active->right_child_node == NULL)
                {
	                active->right_child_node = new_node;
                    new_node->parent = active;
                    tree->node_count_no++;
                    Professional_check_in(tree, new_node);
                    tree->height = tree->root->height;
                    return 1;
                }

                active = active->right_child_node; 
            }
            else
            {
                return 0;
            }
        }
    }

    printf("Node Insertion Failed.\n");
    exit(2);
}
int key_delete_Professional(int key, Professional_AVL *tree)
{
    assert(tree != NULL);
    Professional_Node *del_node = NULL;

    if(!search_by_key_Professional(key, tree, &del_node))
    {
        return 0;
    }

    if(del_node)
    {
        Professional_Node *repl = del_node->left_child_node;
        if(repl == NULL)
        {
            repl = del_node->right_child_node;
        }
        else
        {
            while(repl->right_child_node)
            {
	            repl = repl->right_child_node;
            }
        }

        Professional_Node *rebalance = NULL;
        if(repl)
        {
            if(repl->parent != del_node) 
            {
                rebalance = repl->parent;
            }
            if(repl != del_node->right_child_node)
            {
	            repl->right_child_node = del_node->right_child_node;
	            if(del_node->right_child_node) 
                {
                    del_node->right_child_node->parent = repl;
                }
            }
            if(repl->parent != del_node)
            {
                repl->parent->right_child_node = repl->left_child_node;
                if(repl->left_child_node) 
                {
                    repl->left_child_node->parent = repl->parent;
                }
                repl->left_child_node = del_node->left_child_node;
                del_node->left_child_node->parent = repl;
            }
        }
        else
        {
            if(!rebalance && del_node->parent) 
            {
                rebalance = del_node->parent;
            }
        }
        if(del_node->parent)
        {
            if(del_node->phone_key < del_node->parent->phone_key)
            {
	            del_node->parent->left_child_node = repl;
            }
            else
            {
                del_node->parent->right_child_node = repl;
            }
            if(repl){repl->parent = del_node->parent;}
        }
        else
        {
            tree->root = repl;
            if(repl) {repl->parent = NULL;}
        }

        if(rebalance)
        {
            Professional_check_out(tree, rebalance);
        }
        else
        {
            if(repl){Professional_check_out(tree, repl);}
        }

        if(tree->root)
        {
            tree->height = tree->root->height;
        }
        else
        {
            tree->height = -1;
        }
        tree->node_count_no--;

        free(del_node);
        del_node = NULL;
        return 1;
    }

    return 0;   
}   
int search_by_key_Professional(int key, Professional_AVL *tree, Professional_Node **node)
{
    assert(tree != NULL);
    assert(node != NULL);
    if(tree->root == NULL)
    {
        *node = NULL;
        return 0;
    }

    *node = tree->root;
    while(1)
    {
        if(key < (*node)->phone_key)
        {
            if((*node)->left_child_node == NULL)
            {
	            return 0;
            }
            *node = (*node)->left_child_node;
        }
        else if(key > (*node)->phone_key)
        {
            if((*node)->right_child_node == NULL)
            {
	            return 0;
            }
            *node = (*node)->right_child_node;
        }
        else
        {
            return 1;
        }
    }

    printf("Critical error occured while searching for a node.\n");
    exit(2);
}
int edit_by_key_Professional(int key, Professional_AVL * tree)
{
    assert(tree!=NULL);
    Professional_Node* edit;
    if(!search_by_key_Professional(key,tree,&edit))
    {
        printf("Node not found\n");
        return 0;
    }
    else
    {
        printf("Fields avaliable for editing \n1.name\n2.email\n3.office number\n4.office\n");
        printf("Enter field(complete field for eg type name to edit name) u wish to edit enter all to edit all(excluding phonenum)\n");
        char field[50];
        scanf("%s",field);
        if(strcmp(field,"name")==0)
        {
            printf("Enter new name\n");
            char name[50];
            scanf("%s",name);
            strcpy(edit->name,name);
        }
        else if(strcmp(field,"email")==0)
        {
            printf("Enter new email\n");
            char email[50];
            scanf("%s",email);
            strcpy(edit->email,email);
        }
        else if(strcmp(field,"office")==0)
        {
            printf("Enter new office\n");
            char office[50];
            scanf("%s",office);
            strcpy(edit->office,office);
        }
        else if(strcmp(field,"office number")==0)
        {
            printf("Enter new office number\n");
            char office_num[50];
            scanf("%d",&office_num);
            strcpy(edit->office_number,office_num);
        }
        else if(strcmp(field,"all")==0)
        {
            printf("Enter new name\n");
            char name[50];
            scanf("%s",name);
            strcpy(edit->name,name);
            printf("Enter new email\n");
            char email[50];
            scanf("%s",email);
            strcpy(edit->email,email);
            printf("Enter new office\n");
            char office[50];
            scanf("%s",office);
            strcpy(edit->office,office);
            printf("Enter new office number\n");
            char office_num[50];
            scanf("%d",&office_num);
            strcpy(edit->office_number,office_num);
        }
        else
        {
            printf("Invalid field\n");
        }
        return 1;
    }
}
void print_range_prof(Professional_Node* root,int min_range,int max_range)
{
    if(min_range>max_range) //ensures keys are in right order
    {
        int temp=min_range;
        min_range=max_range;
        max_range=temp;
    }
    if(root==NULL)
    {
        return;
    }
    if(min_range<root->phone_key)
    {
        print_range_prof(root->left_child_node,min_range,max_range);
    }
    if(min_range<=root->phone_key && max_range>=root->phone_key)
    {
        print_node_Professional(root);
    }
    print_range_prof(root->right_child_node,min_range,max_range);
}
Professional_Node* copy_node_2(Professional_Node* node)//create copy of data
{
    Professional_Node *new_node = (Professional_Node *)malloc(sizeof(Professional_Node));
    if(new_node == NULL)
    {
        printf("Malloc Failure,Exiting while generating a new node.\n");
        exit(1); 
    }
    strcpy(new_node->name,node->name);
    strcpy(new_node->email,node->email);
    strcpy(new_node->office,node->office);
    strcpy(new_node->office_number,new_node->office_number);
    new_node->phone_key=node->phone_key;
    new_node->contact_type=PROFESSIONAL_CONTACT;
    new_node->left_child_node = new_node->right_child_node = new_node->parent = NULL;
    new_node->height = 0;
    return new_node;
}
int insert_professional_by_name(Professional_AVL* tree,Professional_Node* node)
{
    assert(tree != NULL); 
    Professional_Node *new_node = copy_node_2(node);
    if(tree->root == NULL)
    {
        tree->root = new_node;
        new_node->parent = NULL;
        tree->height = 0;
        tree->node_count_no++;
        return 1;
    }
    else
    {
        Professional_Node *active = tree->root;
        while(1)
        {
            if(strcmp(new_node->name,active->name)<0 || (strcmp(new_node->name,active->name)==0 && new_node->phone_key<active->phone_key))
            {
	            if(active->left_child_node == NULL)
                {
	                active->left_child_node = new_node;
	                new_node->parent = active;
	                tree->node_count_no++;
	                check_in_professional_name(tree, new_node);
	                tree->height = tree->root->height;
	                return 1;
	            }

	        active = active->left_child_node;
            }
            else if(strcmp(new_node->name,active->name)>0 || (strcmp(new_node->name,active->name)==0 && new_node->phone_key>active->phone_key))
            {
	            if(active->right_child_node == NULL)
                {
	                active->right_child_node = new_node;
                    new_node->parent = active;
                    tree->node_count_no++;
                    check_in_professional_name(tree, new_node);
                    tree->height = tree->root->height;
                    return 1;
                }
                active = active->right_child_node; 
            }
            else
            {
                return 0;
            }
        }
    }

    printf("Node Insertion Failed.\n");
    exit(2);   
}
void create_name_tree_Professional(Professional_AVL* tree,Professional_Node* root)
{
    if(root==NULL)
    {
        return;
    }
    insert_professional_by_name(tree,root);
    create_name_tree_Professional(tree,root->left_child_node);
    create_name_tree_Professional(tree,root->right_child_node);
}
void cleaner_Professional(Professional_Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cleaner_Professional(root->left_child_node);
    cleaner_Professional(root->right_child_node);
    free(root);
}
void clean_Professional(Professional_AVL* tree)
{
    cleaner_Professional(tree->root);
    free(tree);
}
//phonebook functions ------------------>start
void Initialise(phonebook_trees* book) //constructor
{
    book->tree_person = make_personal_tree_empty();
    book->tree_prof = make_Professional_tree_empty();
}
void Insert(phonebook_trees* book)
{
    printf("Press 0 for personal and 1 for professional: \n");
    int choice;
    int flag=0;
    int status;
    scanf("%d",&choice);
    fflush(stdin);
    while(!flag)
    {
        if(choice==0)
        {
            status=insert_new_personal_data
        (book->tree_person);
            flag=1;
        }
        else if(choice==1)
        {
            status=key_insert_newProfessional(book->tree_prof);
            flag=1;
        }
        else
        {
            printf("Please choose 1 or 0\n");
            flag=0;
        }
    }
    if(status==1)
    {
        printf("insertion successful\n");
    }
}
void Edit(phonebook_trees* book)
{
    printf("Press 0 for personal and 1 for professional: \n");
    int choice;
    int flag=0;
    int status,val;
    scanf("%d",&choice);
    printf("Enter the contact number whose details you want to edit: \n");
    scanf("%d",&val);
    fflush(stdin);
    while(!flag)
    {
        if(choice==0)
        {
            status=edit_data_personal(val,book->tree_person);
            flag=1;
        }
        else if(choice==1)
        {
            status=edit_by_key_Professional(val,book->tree_prof);
            flag=1;
        }
        else
        {
            printf("Please choose 1 or 0\n");
            flag=0;
        }
    }
    if(status==1)
    {
        printf("Editing successful\n");
    }
}
void Delete(phonebook_trees* book)
{
    printf("Press 0 for personal and 1 for professional: \n");
    int choice;
    int flag=0;
    int status,val;
    scanf("%d",&choice);
    printf("Enter the contact number which you wish to delete: \n");
    scanf("%d",&val);
    fflush(stdin);
    while(!flag)
    {
        if(choice==0)
        {
            status=delete_new_personal_data
        (val,book->tree_person);
            flag=1;
        }
        else if(choice==1)
        {
            status=key_delete_Professional(val,book->tree_prof);
            flag=1;
        }
        else
        {
            printf("Please choose 1 or 0\n");
            flag=0;
        }
    }
    if(status==1)
    {
        printf("deletion successful\n");
    }   
}
void Search(phonebook_trees* book)
{
    printf("Press 0 for personal and 1 for professional and 2 for both: \n");
    int choice;
    int flag=0;
    int status,val;
    scanf("%d",&choice);
    printf("Enter the contact number which you wish to search: \n");
    scanf("%d",&val);
    fflush(stdin);
    while(!flag)
    {
        if(choice==0)
        {
            Personal_Node* temp;
            status=search_personal_data(val,book->tree_person,&temp);
            flag=1;
            if(status==1)
            {
                print_node_personal(temp);
            }
            else
            {
                printf("Node not found in personal tree\n");
            }
        }
        else if(choice==1)
        {
            Professional_Node* temp;
            status=search_by_key_Professional(val,book->tree_prof,&temp);
            flag=1;
            if(status==1)
            {
                print_node_Professional(temp);
            }
            else
            {
                printf("Node not found in professional tree\n");
            }
        }
        else if(choice==2)
        {
            Personal_Node* temp;
            status=search_personal_data(val,book->tree_person,&temp);
            flag=1;
            if(status==1)
            {
                print_node_personal(temp);
            }
            else
            {
                printf("Node not found in personal tree Searching in professional Tree\n");
            }
            Professional_Node* temp2;
            status=search_by_key_Professional(val,book->tree_prof,&temp2);
            flag=1;
            if(status==1)
            {
                print_node_Professional(temp2);
            }
            else
            {
                printf("Node not found in professional tree\n");
            }
        }
        else
        {
            printf("Please choose 1 or 0\n");
            flag=0;
        }
    }   
}
void Display_sorted(phonebook_trees* book)
{
    printf("Press 0 for personal and 1 for professional and 2 for both: \n");
    int choice;
    int flag=0;
    scanf("%d",&choice);
    fflush(stdin);
    while(!flag)
    {
        if(choice==0)
        {
            int aord;
            printf("press 0 to print personal tree in ascending order, press 1 for descending: \n");
            scanf("%d",&aord);
            if(aord==0)
            {
                inorder_traversal_personal(book->tree_person);
                flag=1;
            }
            else if(aord==1)
            {
                inorder_traversal_personal_reverse(book->tree_person);
                flag=1;
            }
            else
            {
                printf("Enter 0 or 1 only\n");
                flag=0;
            }
        }
        else if(choice==1)
        {
            int aord;
            printf("press 0 to print professional tree in ascending order, press 1 for descending: \n");
            scanf("%d",&aord);
            if(aord==0)
            {
                inorder_traversal_Professional(book->tree_prof);
                flag=1;
            }
            else if(aord==1)
            {
                inorder_traversal_professional_reverse(book->tree_prof);
                flag=1;
            }
            else
            {
                printf("Enter 0 or 1 only\n");
                flag=0;
            }
        }
        else if(choice==2)
        {
            int aord;
            printf("press 0 to print personal tree in ascending order, press 1 for descending: \n");
            scanf("%d",&aord);
            if(aord==0)
            {
                inorder_traversal_personal(book->tree_person);
                inorder_traversal_Professional(book->tree_prof);
                flag=1;
            }
            else if(aord==1)
            {
                inorder_traversal_personal_reverse(book->tree_person);
                inorder_traversal_professional_reverse(book->tree_prof);
                flag=1;
            }
            else
            {
                printf("Enter 0 or 1 only\n");
                flag=0;
            }
        }
        else
        {
            printf("Please choose 1 or 0\n");
            flag=0;
        }
    }   
}


void Print_all(phonebook_trees* book)
{
    printf("Press 0 for personal and 1 for professional and 2 for both: \n");
    int choice;
    int flag=0;
    scanf("%d",&choice);
    fflush(stdin);
    while(!flag)
    {
        if(choice==0)
        {
            inorder_traversal_personal(book->tree_person);
            flag=1;
        }
        else if(choice==1)
        {
            inorder_traversal_Professional(book->tree_prof);
            flag=1;
        }
        else if(choice==2)
        {
            inorder_traversal_personal(book->tree_person);
            inorder_traversal_Professional(book->tree_prof);
            flag=1;
        }
        else
        {
            printf("Please choose 1 or 0\n");
            flag=0;
        }
    } 
}


void Range_search(phonebook_trees* book)
{
    printf("Press 0 for personal and 1 for professional and 2 for both: \n");
    int choice;
    int flag=0;
    scanf("%d",&choice);
    fflush(stdin);
    while(!flag)
    {
        if(choice==0)
        {
            int min_range,max_range;
            printf("Enter the 2 phone numbers seperated by space: ");
            scanf("%d %d",&min_range,&max_range);
            print_range_personal(book->tree_person->root,min_range,max_range);
            flag=1;
        }
        else if(choice==1)
        {
            int min_range,max_range;
            printf("Enter the 2 phone numbers seperated by space: ");
            scanf("%d %d",&min_range,&max_range);
            print_range_prof(book->tree_prof->root,min_range,max_range);
            flag=1;
        }
        else if(choice==2)
        {
            int min_range,max_range;
            printf("Enter the 2 phone numbers seperated by space: ");
            scanf("%d %d",&min_range,&max_range);
            print_range_personal(book->tree_person->root,min_range,max_range);
            print_range_prof(book->tree_prof->root,min_range,max_range);
            flag=1;
        }
        else
        {
            printf("Please choose 1 or 0\n");
            flag=0;
        }
    }   
}

void Sort_by_name(phonebook_trees* book)
{
    printf("Press 0 for personal and 1 for professional and 2 for both:\n");
    int choice;
    int flag=0;
    scanf("%d",&choice);
    fflush(stdin);
    while(!flag)
    {
        if(choice==0)
        {
            Personal_AVL* temp = make_personal_tree_empty();
            create_name_tree_personal(temp,book->tree_person->root);
            inorder_traversal_personal(temp);
            clean_personal(temp);
            flag=1;
        }
        else if(choice==1)
        {
            Professional_AVL* temp = make_Professional_tree_empty();
            create_name_tree_Professional(temp,book->tree_prof->root);
            inorder_traversal_Professional(temp);
            clean_Professional(temp);
            flag=1;            
        }
        else if(choice==2)
        {
            Personal_AVL* temp = make_personal_tree_empty();
            create_name_tree_personal(temp,book->tree_person->root);
            Professional_AVL* temp2 = make_Professional_tree_empty();
            create_name_tree_Professional(temp2,book->tree_prof->root);
            inorder_traversal_personal(temp);
            inorder_traversal_Professional(temp2);
            clean_personal(temp);
            clean_Professional(temp2);
            flag=1;
        }
        else
        {
            printf("Please choose 1 or 0\n");
            flag=0;
        }
    }  
}

void Print_Menu()
{
    printf("The Below are the options:\n");
    printf("___________Menu_____________\n");
    printf("0.Exit\n1.Add a new contact\n2.Edit a contact's details\n3.Delete a contact\n4.Search a contact\n5.Display sorted\n6.Print contact list\n7.Display in range\n8.Display sorted by name\n9.Print The Menu\n");
}

int main()
{
    phonebook_trees Contact_book;
    int choice;
    Initialise(&Contact_book);
    Print_Menu();
    do
    {
        printf("Select the number before your wanted action\nPress 9 to know the Menu: ");
        scanf("%d",&choice);
        fflush(stdin);
        switch (choice)
        {
            case 1:
                Insert(&Contact_book);
                break;
            case 2:
                Edit(&Contact_book);
                break;
            case 3:
                Delete(&Contact_book);
                break;
            case 4:
                Search(&Contact_book);
                break;
            case 5:
                Display_sorted(&Contact_book);
                break;
            case 6:
                Print_all(&Contact_book);
                break;
            case 7:
                Range_search(&Contact_book);
                break;
            case 8:
                Sort_by_name(&Contact_book);
                break;
            case 9:
                Print_Menu();
                break;
            case 0:
                printf("Exiting Program Thank you.......");
                break;
            default:
                printf("Enter number between 0 to 9");
                break;
        }
    }while(choice!=0);
}
