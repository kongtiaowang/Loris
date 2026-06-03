{include file="page_description.tpl"}
{function latestRecursiveCategoryParser level=2 category=array()}
    <div class="container"  id="{$category['Name']|replace:" ":"_"}">
        <h{$level}>{$category['Name']}</h{$level}>
        {if !empty($category['Elements'])}
            <ul>
                {counter start=0 assign=visibleElements}
                {foreach from=$category['Elements'] key=documentID item=document}
                    {if !empty($document['Versions']) && $document['displayLatest'] === '1'}
                        {counter}
                        {foreach from=$document['Versions'] key=versionID item=version}
                            <li>
                                <a
                                    href="/data_release/ajax/GetFile.php?ID={$versionID}"
                                    target="_blank"
                                    class="latest-links"
                                    title="{if $document['DisplayName'] neq $version['DisplayName']}{$document['DisplayName']}{else}{$version['DisplayName']}{/if}"
                                    data-toggle="tooltip"
                                    latest-uploadDate="{$version['UploadDate']}"
                                    latest-filename="{$version['FileName']}"
                                    {if $version['Author'] neq null && $version['Author'] neq ""}
                                        latest-author="{$version['Author']}"
                                    {/if}
                                    {if $version['ReferencePaper'] neq null && $version['ReferencePaper'] neq ""}
                                        latest-reference="{$version['ReferencePaper']}"
                                    {/if}
                                    {if $document['Description'] neq null && $document['Description'] neq ""}
                                        latest-description="{$document['Description']}"
                                    {elseif $version['Description'] neq null && $version['Description'] neq ""}
                                        latest-description="{$version['Description']}"
                                    {/if}
                                    rel="noreferrer noopener">{if $document['DisplayName'] neq null && $document['DisplayName'] neq ""}{$document['DisplayName']}{else}{$version['DisplayName']}{/if} ({$version['UploadDate']})
                                </a>
                            </li>
                            {break}
                        {/foreach}
                    {/if}
                {/foreach}
                {if $visibleElements === 0}
                    <li>Stay Tuned!</li>
                {/if}
            </ul>
        {/if}
        {if !empty($category['SubCategories'])}
            {foreach from=$category['SubCategories'] key=categoryID item=subCategory}
                {latestRecursiveCategoryParser level=$level+1 category=$subCategory}
            {/foreach}
        {/if}
        {if empty($category['Elements']) && empty($category['SubCategories'])}
            <ul>
                <li>Stay Tuned!</li>
            </ul>
        {/if}
    </div>
{/function}
{function historicalRecursiveCategoryParser level=2 category=array()}
    <div class="container" id="{$category['Name']|replace:" ":"_"}">
        <h{$level}>{$category['Name']}</h{$level}>
        {if !empty($category['Elements'])}
            <ul>
                {foreach from=$category['Elements'] key=documentID item=document}
                    {if !empty($document['Versions'])}
                        <li>{$document['DisplayName']}
                            <ul>
                                {foreach from=$document['Versions'] key=versionID item=version}
                                    <li>
                                        <a
                                            href="/data_release/ajax/GetFile.php?ID={$versionID}"
                                            target="_blank"
                                            class="historical-links"
                                            title="{$version['DisplayName']}"
                                            data-toggle="tooltip"
                                            latest-uploadDate="{$version['UploadDate']}"
                                            latest-filename="{$version['FileName']}"
                                            {if $version['Author'] neq null && $version['Author'] neq ""}
                                                latest-author="{$version['Author']}"
                                            {/if}
                                            {if $version['ReferencePaper'] neq null && $version['ReferencePaper'] neq ""}
                                                latest-reference="{$version['ReferencePaper']}"
                                            {/if}
                                            {if $version['Description'] neq null && $version['Description'] neq ""}
                                                latest-description="{$version['Description']}"
                                            {/if}
                                            rel="noreferrer noopener">{$version['DisplayName']} ({$version['UploadDate']})
                                        </a>
                                    </li>
                                {/foreach}
                            </ul>
                        </li>
                    {/if}
                {/foreach}
            </ul>
        {/if}
        {if !empty($category['SubCategories'])}
            {foreach from=$category['SubCategories'] key=categoryID item=subCategory}
                {historicalRecursiveCategoryParser level=$level+1 category=$subCategory}
            {/foreach}
        {/if}
        {if empty($category['Elements']) && empty($category['SubCategories'])}
            <ul>
                <li>Stay Tuned!</li>
            </ul>
        {/if}
    </div>
{/function}
{function addCategoryEditsPanel}
    <div id="categories-panel"
         class="modal fade"
         role="dialog"
         aria-labelledby="categories-panel-label"
         aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                    <button
                        type="button"
                        class="close"
                        data-dismiss="modal"
                        aria-label="Close">
                        <span aria-hidden="true">&times;</span>
                    </button>
                    <h4
                        class="modal-title"
                        id="categories-panel-label">
                        Categories
                    </h4>
                </div>
                <div class="modal-body">
                    <div class="container-fluid">
                        <form method="post" name="edit_categories" id="edit_categories" action="/data_release/">
                            <div
                                id="categories-edit-select-container"
                                class="col-md-10 col-md-offset-1">
                                <select
                                    class="col-md-10 col-md-offset-1"
                                    name="DataReleaseCategoryID"
                                    id="categoriesEditSelect">
                                        <option value="">New Category</option>
                                    {foreach from=$categoriesIndexedByID key=DataReleaseCategoryID item=category}
                                        <option value="{$DataReleaseCategoryID}">{$category["Name"]} ({$DataReleaseCategoryID})</option>
                                    {/foreach}
                                </select>
                            </div>
                            <div
                                id="categories-edit-fields-container"
                                class="col-md-10 col-md-offset-1">
                                <div class="field-container col-md-12">
                                    <label
                                        id="CategoryNameInputLabel"
                                        class="col-md-4"
                                        for="CategoryNameTextInput">
                                        Name
                                    </label>
                                    <input
                                        type="text"
                                        class="col-md-8"
                                        id="CategoryNameTextInput"
                                        name="CategoryNameTextInput"
                                        maxlength="127"
                                        length="50"
                                        required
                                        title="Category's Name"
                                        pattern="^[A-Za-z _\-\(\)0-9'\/]{ldelim}2,127{rdelim}$" />
                                </div>
                                <div class="field-container col-md-12">
                                    <label
                                        id="CategoryParentsInputLabel"
                                        class="col-md-4"
                                        for="CategoryParentsTextInput">
                                        Parents
                                    </label>
                                    <input
                                        type="text"
                                        class="col-md-4"
                                        id="CategoryParentsTextInput"
                                        name="CategoryParentsTextInput"
                                        maxlength="50"
                                        length="10"
                                        required
                                        title="Blank, 42 or 42/49/... (No trailing slash)"
                                        pattern="^(\s*|(\d+(\/\d+)*))$" />
                                </div>
                                <div class="field-container col-md-12">
                                    <label
                                        id="CategoryDisplayOrderInputLabel"
                                        class="col-md-4"
                                        for="CategoryDisplayOrderTextInput">
                                        Display Order
                                    </label>
                                    <input
                                        type="text"
                                        class="col-md-4"
                                        id="CategoryDisplayOrderTextInput"
                                        name="CategoryDisplayOrderTextInput"
                                        maxlength="3"
                                        length="3"
                                        required
                                        title="Order starting at 1 (i.e. 1)"
                                        pattern="^\d{ldelim}1,3{rdelim}$" />
                                </div>
                            </div>
                        </form>
                    </div>
                </div>
                <div class="modal-footer">
                    <button
                        type="button"
                        class="btn btn-default"
                        data-dismiss="modal">
                        Close
                    </button>
                    <button
                        type="submit"
                        form="edit_categories"
                        name="action"
                        value="deleteCategory"
                        id="submit-category-delete"
                        disabled
                        class="btn btn-danger">
                        Delete Category
                    </button>
                    <button
                        type="submit"
                        form="edit_categories"
                        name="action"
                        value="addCategory"
                        id="submit-category-edit"
                        class="btn btn-primary">
                        Add New Category
                    </button>
                </div>
            </div>
        </div>
    </div>
{/function}
{function addDocumentEditsPanel}
    <div id="documents-panel"
         class="modal fade"
         role="dialog"
         aria-labelledby="documents-panel-label"
         aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                    <button
                        type="button"
                        class="close"
                        data-dismiss="modal"
                        aria-label="Close">
                        <span aria-hidden="true">&times;</span>
                    </button>
                    <h4
                        class="modal-title"
                        id="documents-panel-label">
                        Documents
                    </h4>
                </div>
                <div class="modal-body">
                    <div class="container-fluid">
                        <form method="post" name="edit_documents" id="edit_documents" action="/data_release/">
                            <div
                                id="documents-edit-select-container"
                                class="col-md-10 col-md-offset-1">
                                <select
                                    class="col-md-10 col-md-offset-1"
                                    name="DataReleaseDocumentID"
                                    id="DataReleaseDocumentID">
                                    <option value="">New Document</option>
                                    {foreach from=$existingDocuments key=DataReleaseDocumentID item=document}
                                        <option value="{$DataReleaseDocumentID}">{$document["DisplayName"]}</option>
                                    {/foreach}
                                </select>
                            </div>
                            <div
                                id="documents-edit-fields-container"
                                class="col-md-10 col-md-offset-1">
                                <div class="field-container col-md-12">
                                    <label
                                        id="DocumentDisplayNameInputLabel"
                                        class="col-md-4"
                                        for="DocumentDisplayNameTextInput">
                                        Name
                                    </label>
                                    <input
                                        type="text"
                                        class="col-md-8"
                                        id="DocumentDisplayNameTextInput"
                                        name="DocumentDisplayNameTextInput"
                                        maxlength="127"
                                        length="50"
                                        required
                                        title="Document's Name"
                                        pattern="^[A-Za-z _\-\.\(\)0-9'\/]{ldelim}2,127{rdelim}$" />
                                </div>
                                <div class="field-container col-md-12">
                                    <label
                                        id="DocumentDisplayLatestInputLabel"
                                        class="col-md-4 checkbox-label"
                                        for="DocumentDisplayLatestCheckboxInput">
                                        In Latest?
                                    </label>
                                    <input
                                        type="checkbox"
                                        class="col-md-1"
                                        id="DocumentDisplayLatestCheckboxInput"
                                        title="Will the document be displayed in the Latest Panel"
                                        name="DocumentDisplayLatestCheckboxInput"
                                        checked />
                                </div>
                                <div class="field-container col-md-12">
                                    <label
                                        id="DocumentDescriptionInputLabel"
                                        class="col-md-4"
                                        for="DocumentDescriptionTextareaInput">
                                        Description
                                    </label>
                                    <textarea
                                        class="col-md-8"
                                        id="DocumentDescriptionTextareaInput"
                                        name="DocumentDescriptionTextareaInput"
                                        rows="2"
                                        cols="100"
                                        title="Document's description"
                                        maxlength="255"></textarea>
                                </div>
                                <div class="info-table-container col-md-12 well">
                                    <h4 class="text-center">Associated Versions</h4>
                                    <p class="col-md-12">No versions associated with this document.</p>
                                </div>
                                <div class="documents-category-checkboxes-container col-md-12">
                                    <h2 class="text-center">Categories</h2>
                                    {foreach from=$categoriesIndexedByID key=categoryID item=category}
                                        <div class="category-container col-md-6">
                                            <input
                                                class="col-md-1"
                                                type="radio"
                                                value="{$categoryID}"
                                                id="categoryID_{$categoryID}"
                                                required
                                                name="category" />
                                            <label class="col-md-11">
                                                <span class="bold">{$category['Name']}</span>
                                            </label>
                                        </div>
                                    {foreachelse}
                                        <p class="col-md-8 col-offset-2">No categories found. If no categories exist, please add some. If not, please contact your system administrator.</p>
                                    {/foreach}
                                </div>
                            </div>
                        </form>
                    </div>
                </div>
                <div class="modal-footer">
                    <button
                        type="button"
                        class="btn btn-default"
                        data-dismiss="modal">
                        Close
                    </button>
                    <button
                        type="submit"
                        form="edit_documents"
                        name="action"
                        value="deleteDocument"
                        id="submit-document-delete"
                        disabled
                        class="btn btn-danger">
                        Delete Document
                    </button>
                    <button
                        type="submit"
                        form="edit_documents"
                        name="action"
                        value="addDocument"
                        id="submit-document-edit"
                        class="btn btn-primary">
                        Add New Document
                    </button>
                </div>
            </div>
        </div>
    </div>
{/function}
{function addVersionsEditsPanel}
    <div id="versions-panel"
         class="modal fade"
         role="dialog"
         aria-labelledby="versions-panel-label"
         aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                    <button
                        type="button"
                        class="close"
                        data-dismiss="modal"
                        aria-label="Close">
                        <span aria-hidden="true">&times;</span>
                    </button>
                    <h4
                        class="modal-title"
                        id="versions-panel-label">
                        Versions
                    </h4>
                </div>
                <div class="modal-body">
                    <div class="container-fluid">
                        <form method="post" name="edit_versions" id="edit_versions" action="/data_release/">
                            <div
                                id="versions-edit-select-container"
                                class="col-md-10 col-md-offset-1">
                                <select
                                    class="col-md-10 col-md-offset-1"
                                    name="DataReleaseID"
                                    id="DataReleaseID">
                                    {foreach from=$existingVersions key=DataReleaseID item=version}
                                        <option value="{$DataReleaseID}">{$version["FileName"]}</option>
                                    {/foreach}
                                </select>
                            </div>
                            <div
                                id="versions-edit-fields-container"
                                class="col-md-10 col-md-offset-1">
                                <div class="field-container col-md-12">
                                    <label
                                        id="VersionDisplayNameInputLabel"
                                        class="col-md-4"
                                        for="VersionDisplayNameTextInput">
                                        DisplayName
                                    </label>
                                    <input
                                        type="text"
                                        class="col-md-8"
                                        id="VersionDisplayNameTextInput"
                                        name="VersionDisplayNameTextInput"
                                        maxlength="127"
                                        length="50"
                                        title="Display Name of the Version"
                                        required
                                        pattern="^[A-Za-z _\-\.\(\)0-9'\/]{ldelim}2,127{rdelim}$" />
                                </div>
                                <div class="field-container col-md-12">
                                    <label
                                        id="VersionFileNameInputLabel"
                                        class="col-md-4"
                                        for="VersionFileNameTextInput">
                                        FileName
                                    </label>
                                    <input
                                        type="text"
                                        class="col-md-8"
                                        id="VersionFileNameTextInput"
                                        name="VersionFileNameTextInput"
                                        maxlength="255"
                                        length="50"
                                        title="Filename of the version (avoid spaces)"
                                        required
                                        pattern="^[A-Za-z_\-\(\)0-9'\.]{ldelim}2,255{rdelim}$" />
                                </div>
                                <div class="field-container col-md-12">
                                    <label
                                        id="VersionAuthorInputLabel"
                                        class="col-md-4"
                                        for="VersionAuthorTextInput">
                                        Author
                                    </label>
                                    <input
                                        type="text"
                                        class="col-md-8"
                                        id="VersionAuthorTextInput"
                                        name="VersionAuthorTextInput"
                                        maxlength="127"
                                        length="50"
                                        title="Author of the version"
                                        pattern="^[A-Za-z0-9 \(\)\-.'&ÀàÂâÄäÇçÉéÈèÊêÌìÏïÔôÖöÒòÙùÛûÜü]{ldelim}2,127{rdelim}$" />
                                </div>
                                <div class="field-container col-md-12">
                                    <label
                                        id="VersionReferencePaperInputLabel"
                                        class="col-md-4"
                                        for="VersionReferencePaperTextInput">
                                        Reference Paper
                                    </label>
                                    <input
                                        type="text"
                                        class="col-md-8"
                                        id="VersionReferencePaperTextInput"
                                        name="VersionReferencePaperTextInput"
                                        maxlength="255"
                                        length="50"
                                        title="Reference paper of the version"
                                        pattern="^[A-Za-z0-9 \(\)\-:\.,'&ÀàÂâÄäÇçÉéÈèÊêÌìÏïÔôÖöÒòÙùÛûÜü]{ldelim}2,255{rdelim}$" />
                                </div>
                                <div class="field-container col-md-12">
                                    <label
                                        id="VersionUploadDateInputLabel"
                                        class="col-md-4"
                                        for="VersionUploadDateTextInput">
                                        Upload Date
                                    </label>
                                    <input
                                        type="date"
                                        class="col-md-8"
                                        id="VersionUploadDateTextInput"
                                        name="VersionUploadDateTextInput"
                                        title="Date of the version"
                                        max="{$smarty.now|date_format:"%Y-%m-%d"}"
                                        required/>
                                </div>
                                <div class="field-container col-md-12">
                                    <label
                                        id="VersionDescriptionInputLabel"
                                        class="col-md-4"
                                        for="VersionDescriptionTextareaInput">
                                        Description
                                    </label>
                                    <textarea
                                        class="col-md-8"
                                        id="VersionDescriptionTextareaInput"
                                        name="VersionDescriptionTextareaInput"
                                        rows="2"
                                        cols="100"
                                        title="Description of the version"
                                        maxlength="255"></textarea>
                                </div>
                                <div class="field-container col-md-12">
                                    <label
                                        id="VersionsDocumentSelectInputLabel"
                                        class="col-md-4"
                                        for="VersionsDocumentSelectInput">
                                        Documents
                                    </label>
                                    <select
                                        class="col-md-8"
                                        id="VersionsDocumentSelectInput"
                                        name="VersionsDocumentSelectInput">
                                        <option value="">No Document</option>
                                        {foreach from=$existingDocuments key=documentID item=document}
                                            <option value="{$documentID}">{$document['DisplayName']}</option>
                                        {/foreach}
                                    </select>
                                </div>
                            </div>
                        </form>
                    </div>
                </div>
                <div class="modal-footer">
                    <button
                        type="button"
                        class="btn btn-default"
                        data-dismiss="modal">
                        Close
                    </button>
                    <button
                        type="submit"
                        form="edit_versions"
                        name="action"
                        value="deleteVersion"
                        id="submit-version-delete"
                        class="btn btn-danger">
                        Delete
                    </button>
                    <button
                        type="submit"
                        form="edit_versions"
                        name="action"
                        value="editVersion"
                        id="submit-version-edit"
                        class="btn btn-primary">
                        Edit
                    </button>
                </div>
            </div>
        </div>
    </div>
{/function}
{function addUploadPanel}
    <div id="upload-panel"
         class="modal fade"
         role="dialog"
         aria-labelledby="upload-panel-label"
         aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                    <button
                        type="button"
                        class="close"
                        data-dismiss="modal"
                        aria-label="Close">
                        <span aria-hidden="true">&times;</span>
                    </button>
                    <h4
                        class="modal-title"
                        id="upload-panel-label">
                        Upload
                    </h4>
                </div>
                <div class="modal-body">
                    <div class="container-fluid">
                        <form method="post" name="upload_version" enctype="multipart/form-data" id="upload_version" action="/data_release/ajax/FileUpload.php">
                            <div
                                id="upload-version-fields-container"
                                class="col-md-10 col-md-offset-1">
                                <div class="field-container col-md-12">
                                    <label
                                        id="UploadDisplayNameInputLabel"
                                        class="col-md-4"
                                        for="UploadDisplayNameTextInput">
                                        DisplayName
                                    </label>
                                    <input
                                        type="text"
                                        class="col-md-8"
                                        id="UploadDisplayNameTextInput"
                                        name="UploadDisplayNameTextInput"
                                        maxlength="127"
                                        length="50"
                                        required
                                        title="Display Name of the version"
                                        pattern="^[A-Za-z _\-\.\(\)0-9'\/]{ldelim}2,127{rdelim}$" />
                                </div>
                                <div class="field-container col-md-12">
                                    <label
                                        id="UploadAuthorInputLabel"
                                        class="col-md-4"
                                        for="UploadAuthorTextInput">
                                        Author
                                    </label>
                                    <input
                                        type="text"
                                        class="col-md-8"
                                        id="UploadAuthorTextInput"
                                        name="UploadAuthorTextInput"
                                        maxlength="127"
                                        length="50"
                                        title="Author of the version"
                                        value="StoP-AD Centre"
                                        pattern="^[A-Za-z0-9 \(\)\-.'&ÀàÂâÄäÇçÉéÈèÊêÌìÏïÔôÖöÒòÙùÛûÜü]{ldelim}2,127{rdelim}$" />
                                </div>
                                <div class="field-container col-md-12">
                                    <label
                                        id="UploadReferencePaperInputLabel"
                                        class="col-md-4"
                                        for="UploadReferencePaperTextInput">
                                        Reference Paper
                                    </label>
                                    <input
                                        type="text"
                                        class="col-md-8"
                                        id="UploadReferencePaperTextInput"
                                        name="UploadReferencePaperTextInput"
                                        title="Reference paper of the version"
                                        maxlength="255"
                                        length="50"
                                        pattern="^[A-Za-z0-9 \(\)\-,:\.'&ÀàÂâÄäÇçÉéÈèÊêÌìÏïÔôÖöÒòÙùÛûÜü]{ldelim}2,255{rdelim}$" />
                                </div>
                                <div class="field-container col-md-12">
                                    <label
                                        id="UploadDateInputLabel"
                                        class="col-md-4"
                                        for="UploadDateTextInput">
                                        Upload Date
                                    </label>
                                    <input
                                        type="date"
                                        class="col-md-8"
                                        id="UploadDateTextInput"
                                        name="UploadDateTextInput"
                                        title="Upload Date of the version"
                                        max="{$smarty.now|date_format:"%Y-%m-%d"}"
                                        required/>
                                </div>
                                <div class="field-container col-md-12">
                                    <label
                                        id="UploadDescriptionInputLabel"
                                        class="col-md-4"
                                        for="UploadDescriptionTextareaInput">
                                        Description
                                    </label>
                                    <textarea
                                        class="col-md-8"
                                        id="UploadDescriptionTextareaInput"
                                        name="UploadDescriptionTextareaInput"
                                        rows="2"
                                        cols="100"
                                        title="Description of the version"
                                        maxlength="255"></textarea>
                                </div>
                                <div class="field-container col-md-12">
                                    <label
                                        id="UploadDocumentSelectInputLabel"
                                        class="col-md-4"
                                        for="UploadDocumentSelectInput">
                                        Documents
                                    </label>
                                    <select
                                        class="col-md-8"
                                        id="UploadDocumentSelectInput"
                                        name="UploadDocumentSelectInput">
                                        <option value="">No Document</option>
                                        {foreach from=$existingDocuments key=documentID item=document}
                                            <option value="{$documentID}">{$document['DisplayName']}</option>
                                        {/foreach}
                                    </select>
                                </div>
                                <div class="field-container col-md-12">
                                    <label
                                        id="UploadedFileLabel"
                                        class="col-md-4"
                                        for="UploadedFile">
                                        File
                                    </label>
                                    <input
                                        type="file"
                                        id="UploadedFile"
                                        class="col-md-8"
                                        name="file"
                                        required />
                                </div>
                            </div>
                        </form>
                    </div>
                </div>
                <div class="modal-footer">
                    <button
                        type="button"
                        class="btn btn-default"
                        data-dismiss="modal">
                        Close
                    </button>
                    <button
                        type="submit"
                        form="upload_version"
                        name="action"
                        value="UploadVersion"
                        id="submit-upload-version"
                        class="btn btn-primary">
                        Upload
                    </button>
                </div>
            </div>
        </div>
    </div>
{/function}
{function addCategoryButton}
    <button
        type="button"
        class="btn btn-primary btn-md col-md-2"
        data-toggle="modal"
        data-target="#categories-panel">Categories</button>
{/function}
{function addDocumentsButton}
    <button
        type="button"
        class="btn btn-primary btn-md col-md-2 col-md-offset-1"
        data-toggle="modal"
        data-target="#documents-panel">Documents</button>
{/function}
{function addVersionsButton}
    <button
        type="button"
        class="btn btn-primary btn-md col-md-2 col-md-offset-1"
        data-toggle="modal"
        data-target="#versions-panel">Versions</button>
{/function}
{function addUploadButton}
    <button
        type="button"
        class="btn btn-primary btn-md col-md-2 col-md-offset-1"
        data-toggle="modal"
        data-target="#upload-panel">Upload</button>
{/function}
{function addCategoriesData}
    <script>
        categoriesList = {$categoriesIndexedByID|@json_encode};
    </script>
{/function}
{function addDocumentsData}
    <script>
        documentsList = {$existingDocuments|@json_encode};
    </script>
{/function}
{function addVersionsData}
    <script>
        versionsList = {$existingVersions|@json_encode};
    </script>
{/function}
{function addUploadProgressBarModal}
    <div id="progress-bar-modal"
         class="modal fade"
         role="dialog"
         data-backdrop="static"
         aria-labelledby="progress-bar-modal-label"
         aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                    <h4
                        class="modal-title"
                        id="progress-bar-modal-label">
                        Uploading
                    </h4>
                </div>
                <div class="modal-body">
                    <div class="container-fluid">
                        <div class="progress">
                            <div
                                class="progress-bar progress-bar-success progress-bar-striped active"
                                role="progressbar"
                                id="upload-progress-bar"
                                aria-valuenow="0"
                                aria-valuemin="0"
                                aria-valuemax="100"
                                style="width: 0%">0%</div>
                        </div>
                        <div class="progress">
                            <div
                                class="progress-bar progress-bar-danger progress-bar-striped active"
                                role="progressbar"
                                id="stitching-progress-bar"
                                aria-valuenow="0"
                                aria-valuemin="0"
                                aria-valuemax="100"
                                style="width: 0%">0%</div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
{/function}
<div class="jumbotron jumbotron-fluid">
    <div class="container">
        {call name=addDataReleaseDescription}
    </div>
</div>
{if $permissionLevel eq "Edit"}
    {addCategoriesData}
    {addDocumentsData}
    {addVersionsData}
    <div
        id="controls-container"
        class="container col-md-12 col-lg-12 col-sm-12 col-xs-12">
        {addCategoryButton}
        {addDocumentsButton}
        {addVersionsButton}
        {addUploadButton}
    </div>
{/if}
<div class="col-lg-10 col-lg-offset-1 col-md-10 col-md-offset-1 col-sm-10 col-sm-offset-1 col-xs-10 col-xs-offset-1">
    <div class="panel panel-primary panel-default">
        <div id="latest-panel-header" class="panel-heading text-center">
            <h2 class="panel-title" data-toggle="collapse" data-target="#latest-panel-body">Latest Available Data</h2>
        </div>
        <div class="panel-body collapse in" id="latest-panel-body">
            {foreach from=$availableDocuments key=categoryID item=category}
                {latestRecursiveCategoryParser level=2 category=$category}
            {foreachelse}
                <p>No Categories were found. If no categories exist, please add some. If that's not the case, please contact the system administrator.</p>
            {/foreach}
        </div>
    </div>
</div>
<div class="col-lg-10 col-lg-offset-1 col-md-10 col-md-offset-1 col-sm-10 col-sm-offset-1 col-xs-10 col-xs-offset-1">
    <div class="panel panel-primary panel-default">
        <div id="historical-panel-header" class="panel-heading text-center">
            <h2 class="panel-title collapsed emphasis" data-toggle="collapse" data-target="#historical-panel-body">Historical Versions</h2>
        </div>
        <div class="panel-body collapsed collapse" id="historical-panel-body">
            {foreach from=$availableDocuments key=categoryID item=category}
                {historicalRecursiveCategoryParser level=2 category=$category}
            {foreachelse}
                <p>No Categories were found. If no categories exist, please add some. If that's not the case, please contact the system administrator.</p>
            {/foreach}
        </div>
    </div>
</div>
{if $permissionLevel eq "Edit"}
    {addCategoryEditsPanel}
    {addDocumentEditsPanel}
    {addVersionsEditsPanel}
    {addUploadPanel}
    {addUploadProgressBarModal}
{/if}
