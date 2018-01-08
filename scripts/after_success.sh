  #!/bin/bash
  
  # Sends the Coverage Report to Codecov
  bash <(curl -s https://codecov.io/bash)
  
  # Generate Doxygen and deploy to github-pages
  cd $TRAVIS_BUILD_DIR
  chmod +x ./scripts/generateDocumentationAndDeploy.sh
  ./scripts/generateDocumentationAndDeploy.sh