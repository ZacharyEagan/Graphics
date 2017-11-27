#include <Shape.h>


class room
{
public:
   void room(int rand = 0);
   void draw(const std::shared_prtr<Program> prog);

private:
   std::vector<Shape> things
   std::vector<unsigned int> eleBuf;
   std::vector<float> posBuf;
   std::vector<float> norBuf;
   std::vector<float> texBuf;

   unsigned int eleBufID = 0;
   unsigned int posBufID = 0;
   unsigned int norBufID = 0;
   unsigned int texBufID = 0;
   unsigned int vaoID = 0;

};
