from pythreejs import *
from IPython.display import display

class Viewer():
    def __init__(self):
        #print("Viewer initialization")
        self.data = {}
        self.cam = PerspectiveCamera(position=[0, 0, 1], lookAt=[0, 0, 0],fov=30,
                        children=[DirectionalLight(color='white', position=[0, 0, 1], intensity=0.6)])
        self.renderer = Renderer(camera=self.cam, scene = Scene(), controls=[OrbitControls(controlling=self.cam)], 
                    width=600, height=600, antialias=False)
        self.widgets = []

    def set_mesh(self, v, f):
        v = v.astype("float32", copy=False)
        f = f.astype("uint16", copy=False).ravel()

        geometry = BufferGeometry(attributes=dict(
            position=BufferAttribute(v, normalized=False),
            index=BufferAttribute(f, normalized=False)
            #color=BufferAttribute(vertexcolors),
        ))
        geometry.exec_three_obj_method('computeVertexNormals')
        self.mesh = Mesh(geometry=geometry, material=[MeshStandardMaterial(color='#ffdf00', reflectivity=1.0, 
                                                            #side='FrontSide', 
                                                            roughness=0.5, metalness=0.25, flatShading=False,
                                                            polygonOffset=True, polygonOffsetFactor= 1,
                                                            polygonOffsetUnits=1)])

        geon = WireframeGeometry(self.mesh.geometry) # WireframeGeometry
        mat = LineBasicMaterial(color="black", linewidth=0.6)
        wireframe = LineSegments( geon, mat )
        self.mesh.add(wireframe)

        self.scene = Scene(children=[self.mesh, self.cam, AmbientLight(intensity=0.5)], background="#4c4c80")
        self.renderer.scene = self.scene
        
    def add_widget(self, widget, callback):
        self.widgets.append(widget)
        widget.observe(callback, names='value')

    def launch(self):
        display(self.renderer)
        for w in self.widgets:
            display(w)

