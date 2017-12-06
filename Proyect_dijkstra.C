# include <iostream>
# include <tpl_graph.H>		//incluye el tipo de dato List_Digraph
#include<tpl_graph_utils.H>	//incluye la clase Distance
#include<string>
#include <Dijkstra.H>		//very obvious

using namespace std;

// Alias para el tipo de nodo y arco.
using Node = Graph_Node<string>;
using Arc = Graph_Arc<float>;


// Alias para el tipo de grafo
using GT = List_Digraph<Node,Arc>;


void print_graph(GT & g)
{
  // Imprime la cantidad de nodos del grafo
  cout << g.get_num_nodes() << " nodes\n";

  // Itera sobre el conjunto completo de nodos
  for (GT::Node_Iterator it(g); it.has_curr(); it.next())
    {
      auto p = it.get_curr();

      // Imprime la cantidad de arcos adyacentes a p
      cout << "Node " << p->get_info() << ", "
	   << g.get_num_arcs(p) << " adjacent arcs: ";

      // Para el nodo que está visitando, itera sobre todos sus arcos adyacentes.
      for (GT::Node_Arc_Iterator ait(p); ait.has_curr(); ait.next())
	{
	  // Obtiene el nodo adyacente a p
	  auto q = ait.get_tgt_node();
	  cout << q->get_info() << ' ';
	}

      cout << endl;
    }

 cout << endl << endl;

  // Imprime la cantidad total de arcos del grafo
  cout << g.get_num_arcs() << " arcs\n";

  // Itera sobre todos los arcos del grafo.
  for (GT::Arc_Iterator it(g); it.has_curr(); it.next())
    {
      auto a = it.get_curr();

      auto p = g.get_src_node(a);
      auto q = g.get_tgt_node(a);

      cout << p->get_info() << " --> " << q->get_info() << " con peso --> "<< a->get_info()<<endl;
    }
}

int main()
{
  GT graph, dijkstra_test; //por using es lo mismo que usar List_Digraph<Graph_Node<char>,GraphArc<Int>> graph;


//Ahora todos los nodos

	auto MR5A = graph.insert_node("Redoma 5 aguilas blancas");
	auto MCSF = graph.insert_node("calle San Francisco");
	auto MCSD0 = graph.insert_node("calle san diego A");
	auto MCSD1 = graph.insert_node("calle san diego B");
	auto MCSD2 = graph.insert_node("calle san diego C");
	auto MCSD3 = graph.insert_node("calle san diego D");
	auto MCACM = graph.insert_node("Cll la Aguada - Calle la Montaña");
	auto MCLA = graph.insert_node("Calle La Aguada");
	auto MACP = graph.insert_node("Calle la Aguada- Calle Pico Espejo");
	auto M1 = graph.insert_node("Calle 1");
	auto M1E = graph.insert_node("Calle 1 final");
	auto M2 = graph.insert_node("Calle 2");
	auto M2E = graph.insert_node("Calle 2 final");
	auto M3 = graph.insert_node("Calle Loma Redonda Esquina Cll. La Montaña");
	auto M4 = graph.insert_node("Cll. La Montaña - Cll. Loma Redonda");
	auto M5 = graph.insert_node("Cll. Nevados - Cll. Pico Espejo");
	auto M6 = graph.insert_node("Cll. 3 - Cll. Hoyada de Milla");
	auto M7 = graph.insert_node("Cll 3 Interseccion");
	auto M8 = graph.insert_node("Cll. 3 Final");
	auto M9 = graph.insert_node("Cll. 4 - Cll. 5");
	auto M10 = graph.insert_node("Calle 4");
	auto M11 = graph.insert_node("Calle 4 - Hoyada de Milla");
	auto M12 = graph.insert_node("Calle 5 - Hoyada de Milla");
	auto M13 = graph.insert_node("Calle 6 - Hoyada de Milla");
	auto M14 = graph.insert_node("Calle 7 - Hoyada de Milla");
	auto M15 = graph.insert_node("Antes de la redoma");
	auto M16 = graph.insert_node("Redoma de la avenida universidad");
	auto M17 = graph.insert_node("Calle 7 - Avenida Universidad");
	auto M18 = graph.insert_node("Calle 8 - Avenida Universidad");
	auto M19 = graph.insert_node("Interseccion Av. Universidad - La Milagrosa");
	auto M20 = graph.insert_node("Calle Los Nevados - Calle Yagrumo");
	auto M21 = graph.insert_node("Chorros - MIlagrosa");
	auto M22 = graph.insert_node("Enlace Charles Chaplin");
	auto M23 = graph.insert_node("Enlace German Briceño");
	auto M24 = graph.insert_node("Gran Mision Vivienda Venezuela Plaza Toros");
	auto M25 = graph.insert_node("Plaza de Toros - Avda. Las Americas");
	auto M26 = graph.insert_node("CLL 11 - AV 2");
	auto M27 = graph.insert_node("CLL 11 - AV 1");
	auto M28 = graph.insert_node("CLL 12 - AV 2");
	auto M29 = graph.insert_node("CLL 12 - AV 1");
	auto M30 = graph.insert_node("CLL 13 - AV 1");
	auto M31 = graph.insert_node("CLL 13 - AV 2");
	auto M32 = graph.insert_node("CLL 14 - AV 2");
	auto M33 = graph.insert_node("CLL 14 - AV 1");
	auto M34 = graph.insert_node("CLL 13 - AV 3");
	auto M35 = graph.insert_node("CLL 14 - AV 3");
	auto M36 = graph.insert_node("CLL 13 - AV 4");
	auto M37 = graph.insert_node("CLL 13 - AV 5");
	auto M38 = graph.insert_node("CLL 14 - AV 4");
	auto M39 = graph.insert_node("CLL 14 - AV 5");
	auto M40 = graph.insert_node("CLL 14 - AV 6");
	auto M41 = graph.insert_node("CLL 15 - AV 1");
	auto M42 = graph.insert_node("CLL 15 - AV 2");
	auto M43 = graph.insert_node("CLL 15 - AV 3");
	auto M44 = graph.insert_node("CLL 15 - AV 4");
	auto M45 = graph.insert_node("CLL 15 - AV 5");
	auto M46 = graph.insert_node("CLL 15 - AV 6");
	auto M47 = graph.insert_node("CLL 15 - AV 7");
	auto M48 = graph.insert_node("CLL 16 - AV 1");
	auto M49 = graph.insert_node("CLL 16 - AV 2");
	auto M50 = graph.insert_node("CLL 16 - AV 3");
	auto M51 = graph.insert_node("CLL 16 - AV 4");
	auto M52 = graph.insert_node("CLL 16 - AV 5");
	auto M53 = graph.insert_node("CLL 16 - AV 6");
	auto M54 = graph.insert_node("CLL 16 - AV 7");
	auto M55 = graph.insert_node("CLL 16 - AV 8");
	auto M56 = graph.insert_node("CLL 17 - AV 1");
	auto M57 = graph.insert_node("CLL 17 - AV 2");
	auto M58 = graph.insert_node("CLL 17 - AV 3");
	auto M59 = graph.insert_node("CLL 17 - AV 4");
	auto M60 = graph.insert_node("CLL 17 - AV 5");
	auto M61 = graph.insert_node("CLL X1 - AV 7");
	auto M62 = graph.insert_node("CLL X1 - AV 8");
	auto M63 = graph.insert_node("CLL 17 - AV 7");
	auto M64 = graph.insert_node("CLL 17 - AV 8");
	auto M65 = graph.insert_node("AV 8 - Pasaje Sanchez");
	auto M66 = graph.insert_node("Pasaje Sanchez - CLL X1");
	auto M67 = graph.insert_node("CLL 17 - Pasaje Sanchez");
	auto M68 = graph.insert_node("CLL 17 - AV 6");
	auto M69 = graph.insert_node("CLL Y1 - AV 8");
	auto M70 = graph.insert_node("CLL Y1 - Pasaje Sanchez");
	auto M71 = graph.insert_node("CLL 18 - AV 1");
	auto M72 = graph.insert_node("CLL 18 - AV 2");
	auto M73 = graph.insert_node("CLL 18 - AV 3");
	auto M74 = graph.insert_node("CLL 18 - AV 4");
	auto M75 = graph.insert_node("CLL 18 - AV 5");
	auto M76 = graph.insert_node("CLL 18 - AV 6");
	auto M77 = graph.insert_node("CLL 18 - AV 7");
	auto M78 = graph.insert_node("CLL 18 - AV 8");
	auto M79 = graph.insert_node("CLL 19 - AV 1");
	auto M80 = graph.insert_node("CLL 19 - AV 2");
	auto M81 = graph.insert_node("CLL 19 - AV 3");
	auto M82 = graph.insert_node("CLL 19 - AV 4");
	auto M83 = graph.insert_node("CLL 19 - AV 5");
	auto M84 = graph.insert_node("CLL 19 - AV 6");
	auto M85 = graph.insert_node("CLL 19 - AV 7");
	auto M86 = graph.insert_node("CLL 19 - AV 8");
	auto M87 = graph.insert_node("CLL 18 - Pasaje Sanchez");
	auto M88 = graph.insert_node("CLL 20 - AV 1");
	auto M89 = graph.insert_node("CLL 20 - AV 2");
	auto M90 = graph.insert_node("CLL 20 - AV 3");
	auto M91 = graph.insert_node("CLL 20 - AV 4");
	auto M92 = graph.insert_node("CLL 20 - AV 5");
	auto M93 = graph.insert_node("CLL 20 - AV 6");
	auto M94 = graph.insert_node("CLL 20 - AV 7");
	auto M95 = graph.insert_node("CLL 20 - AV 8");
	auto M96 = graph.insert_node("CLL 21 - AV 3");
	auto M97 = graph.insert_node("CLL 21 - AV 4");
	auto M98 = graph.insert_node("CLL 21 - AV 5");
	auto M99 = graph.insert_node("CLL 21 - AV 6");
	auto M100 = graph.insert_node("CLL 21 - AV 7");
	auto M101 = graph.insert_node("CLL 21 - AV 8");
	auto M102 = graph.insert_node("CLL 22 - AV 5");
	auto M103 = graph.insert_node("CLL 22 - AV 6");
	auto M104 = graph.insert_node("CLL 22 - AV 7");
	auto M105 = graph.insert_node("CLL 22 - AV 8");
	auto M106 = graph.insert_node("CLL 23 - AV 4");
	auto M107 = graph.insert_node("CLL 23 - AV 5");
	auto M108 = graph.insert_node("CLL 23 - AV 6");
	auto M109 = graph.insert_node("CLL 23 - AV 7");
	auto M110 = graph.insert_node("CLL 23 - AV 8");
	auto M110a = graph.insert_node("CLL 24 - AV 2");
	auto M111 = graph.insert_node("CLL 24 - AV 3");
	auto M112 = graph.insert_node("CLL 24 - AV 4");
	auto M113 = graph.insert_node("CLL 24 - AV 5");
	auto M114 = graph.insert_node("CLL 24 - AV 6");
	auto M115 = graph.insert_node("CLL 24 - AV 7");
	auto M116 = graph.insert_node("CLL 24 - AV 8");
	auto M117 = graph.insert_node("CLL 24 - ?av");
	auto M118 = graph.insert_node("CLL 24 - CLL 25");
	auto M119 = graph.insert_node("CLL 25 - AV 2");
	auto M120 = graph.insert_node("CLL 25 - AV 3");
	auto M121 = graph.insert_node("CLL 25 - AV 4");
	auto M122 = graph.insert_node("CLL 25 - AV 5");
	auto M123 = graph.insert_node("CLL 25 - AV 6");
	auto M124 = graph.insert_node("CLL 25 - AV 7");
	auto M125 = graph.insert_node("CLL 25 - AV 8");
	auto M126 = graph.insert_node("CLL 25 - ?av");
	auto M127 = graph.insert_node("CLL 25 - ?av1");
	auto M128 = graph.insert_node("CLL Extra de la av 8 - AV  extra cerca del teleferico");
	auto M129 = graph.insert_node("CLL Extra 2 de la av 8 - AV  extra cerca del teleferico");
	auto M130 = graph.insert_node("CLL 26 - AV 8");
	auto M131 = graph.insert_node("CLL ? - AV 8");
	auto M132 = graph.insert_node("CLL 26 - AV 2");
	auto M133 = graph.insert_node("CLL 26 - AV 3");
	auto M134 = graph.insert_node("CLL 26 - AV 4");
	auto M135 = graph.insert_node("CLL 26 - AV 5");
	auto M136 = graph.insert_node("CLL 26 - AV 6");
	auto M137 = graph.insert_node("CLL 26 - AV 7");
	auto M138 = graph.insert_node("CLL 27 - AV 2");
	auto M139 = graph.insert_node("CLL 27 - AV 3");
	auto M140 = graph.insert_node("CLL 27 - AV 4");
	auto M141 = graph.insert_node("CLL 28 - AV 2");
	auto M142 = graph.insert_node("CLL 28 - AV 3");
	auto M143 = graph.insert_node("CLL 28 - AV 4");
	auto M144 = graph.insert_node("CLL 29 - AV 2");
	auto M145 = graph.insert_node("CLL 29 - AV 3");
	auto M146 = graph.insert_node("CLL 29 - AV 4");
	auto M147 = graph.insert_node("CLL 30 - AV 2");
	auto M148 = graph.insert_node("CLL 30 - AV 3");
	auto M149 = graph.insert_node("CLL 30 - AV 4");
	auto M150 = graph.insert_node("CLL 31 - AV 2");
	auto M151 = graph.insert_node("CLL 31 - AV 3");
	auto M152 = graph.insert_node("CLL 31 - AV 4");
	auto M153 = graph.insert_node("Milagrosa - Chorros 2");
	auto M154 = graph.insert_node("Chorros - Geografia");
	auto M155 = graph.insert_node("Amparo - Chorros - Forestal");
	auto M156 = graph.insert_node("Chorros - pasaje 1 Chorros");
	auto M157 = graph.insert_node("Chorros - pasaje 2 Chorros");
	auto M158 = graph.insert_node("Chorros - Forestal - Tia Mila");
	auto M158a = graph.insert_node("Ciclo Basico");
	auto M159 = graph.insert_node("Dentro de forestales");
	auto M160 = graph.insert_node("CEFAP");
	auto M161 = graph.insert_node("Chorros - Pasaje Quintero");
	auto M162 = graph.insert_node("Chorros - Calle 1 Chorros");
	auto M163 = graph.insert_node("Chorros - Mas arriba calle 1 Chorros");
	auto M164 = graph.insert_node("Chorros -  Cll. EL Conuco");
	auto M165 = graph.insert_node("Enlace Chorros - Hechicera");
	auto M166 = graph.insert_node("Redoma de los chorros - Zoologico");
	auto M167 = graph.insert_node("Chorros Calles 1 2 y 3");
	auto M168 = graph.insert_node("Autolavado - Recta Hechicera - San Pedro");
	auto M169 = graph.insert_node("Primera entrada Ingenieria");
	auto M170 = graph.insert_node("Parada de BIACI");
	auto M171 = graph.insert_node("Arquitectura");
	auto M172 = graph.insert_node("Entrada Sta. Rosa");
	auto M173 = graph.insert_node("Otra entrada Deportes");
	auto M174 = graph.insert_node("Estadio Bajando - Recta Hechicera");
	auto aux1 = graph.insert_node("Hechicera - Nodo Auxiliar");
	auto M175 = graph.insert_node("Bifurcacion");
	auto M176 = graph.insert_node("Conjunto Residencial la Hechicera 1");
	auto M177 = graph.insert_node("CC la Hechicera");
	auto M178 = graph.insert_node("Conjunto Residencial la Hechicera 2");
	auto M179 = graph.insert_node("Entrada sta. Ana");
	auto M180 = graph.insert_node("La Escena Bar");
	auto M181 = graph.insert_node("Jardin Botanico");
	auto M182 = graph.insert_node("Estacion de Servicio la Hechicera");
	auto M183 = graph.insert_node("Mukumbarila");
	auto M184 = graph.insert_node("Av Universidad -  Calle Yagrumo");
	auto M185 = graph.insert_node("Av Universidad - El Bosque");
	auto M186 = graph.insert_node("El Amparo");
	auto M186a = graph.insert_node("Av Universidad - Chorros");
	auto M187 = graph.insert_node("El Amparo - El Bosque");
	auto M188 = graph.insert_node("El Bosque");
	auto M189 = graph.insert_node("Albarregas 1");
	auto M190 = graph.insert_node("Albarregas 2");



// auto nombre = GT.insert_node('value');

//GT.insert_arc(src,target,weight)

//Ahora todos los Arcos

  graph.insert_arc(M1E,M1,144.75);
  graph.insert_arc(M1,M1E,144.75);
  graph.insert_arc(M1,M2,40.92);
  graph.insert_arc(M2,M1,40.92);
  graph.insert_arc(M2,M2E,179.01);
  graph.insert_arc(M2,MR5A,43.2);
  graph.insert_arc(M2E,M2,179.01);
  graph.insert_arc(MR5A,M2,43.2);
  graph.insert_arc(MR5A,MCSF,156.25);
  graph.insert_arc(MR5A,M185,616.64);
  graph.insert_arc(MCSF,MR5A,156.25);
  graph.insert_arc(MCSF,MCSD0,52.15);
  graph.insert_arc(MCSD0,MCSF,52.15);
  graph.insert_arc(MCSD0,MCSD1,78.42);
  graph.insert_arc(MCSD1,MCSD2,110.76);
  graph.insert_arc(MCSD2,MCSD3,69.52);
  graph.insert_arc(MCSD3,MCSD0,104.92);
  graph.insert_arc(M185,M186a,202.82);
  graph.insert_arc(M185,M188,46.03);
  graph.insert_arc(M186a,M21,110.48);
  graph.insert_arc(M186a,M19,53.32);
  graph.insert_arc(M188,M185,46.03);
  graph.insert_arc(M188,M187,48.08);
  graph.insert_arc(M19,M184,460.11);
  graph.insert_arc(M19,M21,99.97);
  graph.insert_arc(M19,M16,718.74);
  graph.insert_arc(M184,MR5A,404.99);
  graph.insert_arc(M187,M188,48.08);
  graph.insert_arc(M187,M186,164.38);
  graph.insert_arc(M186,M187,164.38);
  graph.insert_arc(M186,M155,161.44);
  graph.insert_arc(M155,M186,161.44);
  graph.insert_arc(M155,M154,118.39);
  graph.insert_arc(M155,M159,162);
  graph.insert_arc(M155,M156,464.47);
  graph.insert_arc(M21,M154,279.46);
  graph.insert_arc(M21,M153,163.8);
  graph.insert_arc(M153,M182,870.65);
  graph.insert_arc(M158a,M153,182.56);
  graph.insert_arc(M154,M158a,75.13);
  graph.insert_arc(M154,M155,118.39);
  graph.insert_arc(M156,M155,484.47);
  graph.insert_arc(M156,M157,48.61);
  graph.insert_arc(M157,M156,48.61);
  graph.insert_arc(M157,M158,238);
  graph.insert_arc(M158,M157,238);
  graph.insert_arc(M158,M160,427.5);
  graph.insert_arc(M158,M161,176.08);
  graph.insert_arc(M159,M155,162);
  graph.insert_arc(M159,M160,307.4);
  graph.insert_arc(M160,M159,307.4);
  graph.insert_arc(M160,M158,427.5);
  graph.insert_arc(M154,M155,118.39);
  graph.insert_arc(M161,M158,176.08);
  graph.insert_arc(M161,M162,59.63);
  graph.insert_arc(M162,M163,54.45);
  graph.insert_arc(M162,M161,59.63);
  graph.insert_arc(M163,M164,95.49);
  graph.insert_arc(M163,M162,54.45);
  graph.insert_arc(M164,M165,228.48);
  graph.insert_arc(M164,M163,95.49);
  graph.insert_arc(M165,M167,203.23);
  graph.insert_arc(M165,M168,252.12);
  graph.insert_arc(M167,M165,42.19);
  graph.insert_arc(M167,M166,202.23);
  graph.insert_arc(M166,M167,42.19);
  graph.insert_arc(M168,M165,252.12);
  graph.insert_arc(M168,M175,372.93);
  graph.insert_arc(M168,aux1,100.49);
  graph.insert_arc(aux1,M175,103.6);
  graph.insert_arc(aux1,M169,290.53);
  graph.insert_arc(aux1,M168,100.49);
  graph.insert_arc(M175,aux1,103.6);
  graph.insert_arc(M175,M168,372.93);
  graph.insert_arc(M175,M174,379.01);



  //print_graph(graph);

  Aleph::Dijkstra_Min_Paths<GT> dijkstra; //Creo una variable donde se encuentra el algoritmo dijkstra
  dijkstra(graph,M1, dijkstra_test); //Ejecuto el codigo dijkstra para el grafo "graph", empezando en M1 y guardando el arbol abarcados en el dijkstra_test
  print_graph(dijkstra_test); //imprimo el arbol abarcador
  return 0;
}
