#include <stdio.h>
#include <string.h>
#include <libxml/parser.h>

void extraction(FILE *f)
{
    xmlDoc         *document;
    xmlNode        *root, *first_child, *node;
    char           *filename;

    // if (argc < 2) {
    //     fprintf(stderr, " veuiller renseigner le fichier.xml a extraire\n");
    //     return 1;
    // }
    // filename = argv[1];

    document = xmlReadFile(f, NULL, 0);
    root = xmlDocGetRootElement(document);
    fprintf(stdout, "Root is <%s> (%i)\n", root->name, root->content);
    first_child = root->children;
    for (node = first_child; node; node = node->next) {
        fprintf(stdout, "\t Child is <%s> (%i)\n", node->name, node->content);
    }
    fprintf(stdout, "...\n");
    return 0;

}