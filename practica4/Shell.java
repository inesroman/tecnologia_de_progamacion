//----------------------------------------------------
// File: Shell.java
// Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
// Fecha: 04/04/2023
//----------------------------------------------------

import java.util.ArrayList;

public class Shell {
    private ArrayList<Directorio> route;

    public Shell() { 
        route = new ArrayList<Directorio>();
        Directorio dir = new Directorio("/");
        route.add(dir);
    }

    public String pwd() {
        String s = "";
        for(int i = 0; i < route.size(); i++) {
            s += route.get(i).getName();
            if((i < (route.size() - 1)) && (i != 0)) s += "/";
        }
        return s;
    }

    public String ls() {
        return route.get(route.size()-1).getListOfContents();
    }

    public String du() {
        return route.get(route.size()-1).getListOfContentsAndSize();
    }

    public void vi(String name, int size) {
        try {
            Directorio dir = route.get(route.size() - 1);
            if(dir.contains(name)) {
                int index = dir.getIndexOf(name);
                Nodo encontrado = dir.getContent().get(index);
                if(encontrado instanceof Fichero) {
                    Fichero ficheroEncontrado = (Fichero) encontrado;
                    ficheroEncontrado.setSize(size);
                } else {
                    // EXCEPCION: YA EXISTE ENLACE O DIR CON NOMBRE NAME
                    throw new ExcepcionExisteDirOLink(encontrado.getName()); 
                }
            } else {
                Fichero fich = new Fichero(name, size);
                dir.add(fich);
            }
        }

        catch (ExcepcionExisteDirOLink e) {
            System.out.println(e.toString());
        }
    }

    public void mkdir(String name) {
        try {
            if(route.get(route.size() - 1).contains(name)) {
                // EXCEPCION: YA EXISTE NODO CON NOMBRE NAME
                throw new ExcepcionExisteNodo(name);
            } 
            Directorio dir = new Directorio(name); 
            route.get(route.size() -1 ).add(dir);
        }
        catch (ExcepcionExisteNodo e) {
            System.out.println(e.toString());
        }
        
    }

    public void cd(String path) {
        try {
            String[] s = path.split("/");
            ArrayList<Directorio> copyRoute;
            if(path.substring(0, 1).equals("/")) {
                copyRoute = new ArrayList<>();
                copyRoute.add((Directorio)route.get(0));
            } else {
                copyRoute = new ArrayList<>(route);
            }           
            for(int i = 0; i < s.length; i++) {
                if(s[i].equals("..") && copyRoute.size() > 1) {
                    copyRoute.remove(copyRoute.size() - 1);
                } else if(s[i].equals("..")) {
                    // EXCEPCION: NO EXISTE EL DIRECTORIO PADRE
                    throw new ExcepcionNoExistePadre(copyRoute.get(copyRoute.size()-1).getName());
                } else if(s[i].equals(".") || s[i].equals("")) { // No se hace nada
                } else {               
                    Directorio dir = copyRoute.get(copyRoute.size() - 1);
                    int index = dir.getIndexOf(s[i]);
                    if(index > -1) {
                        if(dir.getContent().get(index) instanceof Directorio) {
                            copyRoute.add((Directorio)dir.getContent().get(index));
                        } else {
                            // EXCEPCION: NO ES UN DIRECTORIO
                            throw new ExcepcionNoEsDir(dir.getContent().get(index).getName());
                        }
                    } else {
                        // EXCEPCION: NO EXISTE EL DIRECTORIO
                        throw new ExcepcionNoExisteDir(s[i]);
                    }
                }
            }
            route = copyRoute;
        }
        catch (ExcepcionNoExisteDir e) {
            System.out.println(e.toString());
        }
        catch (ExcepcionNoExistePadre e) {
            System.out.println(e.toString());
        }
        catch (ExcepcionNoEsDir e) {
            System.out.println(e.toString());
        }
    }

    public void ln(String path, String name) {
        try {
            if(route.get(route.size() - 1).contains(name)) {
                throw new ExcepcionExisteNodo(name);
            } else {
                ArrayList<Nodo> link;
                if(path.substring(0, 1).equals("/")) {
                    link = new ArrayList<>();
                    link.add(route.get(0));
                } else {
                    link = new ArrayList<>(route);
                } 
                String[] s = path.split("/");
                for(int i = 0; i < s.length; i++) {
                    if(s[i].equals("..") && link.size() > 1) {
                        link.remove(link.size() - 1);
                    } else if(s[i].equals("..")) {
                        // EXCEPCION: NO EXISTE EL DIRECTORIO PADRE
                        throw new ExcepcionNoExistePadre(link.get(link.size()-1).getName());
                    } else if(s[i].equals(".") || s[i].equals("")) { // No se hace nada
                    } else {               
                        Nodo n = link.get(link.size() - 1);
                        if(n instanceof Directorio) {
                            Directorio dir = (Directorio) n;
                            int index = dir.getIndexOf(s[i]);
                            if(index > -1) {
                                    link.add(dir.getContent().get(index));
                            } else {
                                // EXCEPCION: NO EXISTE EL NODO
                                throw new ExcepcionNoExisteNodo(s[i]); 
                            }
                        } else {
                            // EXCEPCION: LOS FICHEROS Y ENLACES NO CONTIENEN OTROS NODOS
                            throw new ExcepcionNoEsDir(n.getName());
                        }
                    }
                }
                
                Enlace e = new Enlace(name, link.get(link.size() - 1)); 
                route.get(route.size() -1 ).add(e);
            }
        }

        catch (ExcepcionExisteNodo e) {
            System.out.println(e.toString());
        }

        catch (ExcepcionNoExistePadre e) {
            System.out.println(e.toString());
        }

        catch (ExcepcionNoExisteNodo e) {
            System.out.println(e.toString());
        }

        catch (ExcepcionNoEsDir e) {
            System.out.println(e.toString());
        }

    }

    public int stat(String path) {
        try {
            String[] s = path.split("/");
            ArrayList<Nodo> link;
            if(path.substring(0, 1).equals("/")) {
                link = new ArrayList<>();
                link.add(route.get(0));
            } else {
                link = new ArrayList<>(route);
            } 
            for(int i = 0; i < s.length; i++) {
                if(s[i].equals("..") && link.size() > 1) {
                    link.remove(link.size() - 1);
                } 
                else if(s[i].equals("..")) {
                    // EXCEPCION: NO EXISTE EL DIRECTORIO PADRE
                    throw new ExcepcionNoExistePadre(link.get(link.size()-1).getName());
                } 
                else if(s[i].equals(".") || s[i].equals("")) { // No se hace nada
                } 
                else {               
                    Nodo n = link.get(link.size() - 1);
                    if (n instanceof Directorio) {
                        Directorio dir = (Directorio) n;
                        int index = dir.getIndexOf(s[i]);
                        if(index > -1) {
                                link.add(dir.getContent().get(index));
                        } 
                        else {
                            // EXCEPCION: NO EXISTE EL NODO 
                            throw new ExcepcionNoExisteNodo(s[i]); 
                        }
                    } 
                    else {
                        // EXCEPCION: LOS FICHEROS Y ENLACES NO CONTIENEN OTROS NODOS
                        throw new ExcepcionNoEsDir(n.getName()); 
                    }
                }
            }
            return link.get(link.size() - 1).getSize(0);
        }

        catch (ExcepcionNoExistePadre e) {
            System.out.println(e.toString());
            return -1;
        }

        catch (ExcepcionNoExisteNodo e) {
            System.out.println(e.toString());
            return -1;
        }

        catch (ExcepcionNoEsDir e) {
            System.out.println(e.toString());
            return -1;
        }
    }

    public void rm(String path) {
        try {
            String[] s = path.split("/");
            ArrayList<Directorio> copyRoute;
            if(path.substring(0, 1).equals("/")) {
                copyRoute = new ArrayList<>();
                copyRoute.add((Directorio)route.get(0));
            } else {
                copyRoute = new ArrayList<>(route);
            }
            for(int i = 0; i < s.length - 1; i++) {
                if(s[i].equals("..") && copyRoute.size() > 1) {
                    copyRoute.remove(copyRoute.size() - 1);
                } else if(s[i].equals("..")) {
                    // EXCEPCION: NO EXISTE EL DIRECTORIO PADRE
                    throw new ExcepcionNoExistePadre(copyRoute.get(copyRoute.size()-1).getName());
                } else if(s[i].equals(".") || s[i].equals("")) { // No se hace nada
                } else {               
                    Directorio dir = copyRoute.get(copyRoute.size() - 1);
                    int index = dir.getIndexOf(s[i]);
                    if(index > -1) {
                        if(dir.getContent().get(index) instanceof Directorio) {
                            copyRoute.add((Directorio)dir.getContent().get(index));
                        } else {
                            // EXCEPCION: LOS FICHEROS Y ENLACES NO CONTIENEN OTROS NODOS
                            throw new ExcepcionNoEsDir(dir.getContent().get(index).getName()); 
                        }
                    } else {
                        // EXCEPCION: NO EXISTE EL NODO
                        throw new ExcepcionNoExisteNodo(s[i]);
                    }
                }
            }
            if(copyRoute.get(copyRoute.size() - 1).contains(s[s.length - 1])) {
                copyRoute.get(copyRoute.size() - 1).remove(s[s.length - 1]);
            } else {
                // EXCEPCION: NO EXISTE EL NODO 
                throw new ExcepcionNoExisteNodo(s[s.length - 1]); 
            }
        }

        catch (ExcepcionNoEsDir e) {
            System.out.println(e.toString());
        }
        catch (ExcepcionNoExistePadre e) {
            System.out.println(e.toString());
        }
        catch (ExcepcionNoExisteNodo e) {
            System.out.println(e.toString());
        }
    }
}
